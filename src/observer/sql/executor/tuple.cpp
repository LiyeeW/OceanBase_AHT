/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2021/5/14.
//

#include "sql/executor/tuple.h"
#include "storage/common/table.h"
#include "common/log/log.h"

Tuple::Tuple(const Tuple &other) {
  LOG_PANIC("Copy constructor of tuple is not supported");
  exit(1);
}

Tuple::Tuple(Tuple &&other) noexcept : values_(std::move(other.values_)) {
}

Tuple & Tuple::operator=(Tuple &&other) noexcept {
  if (&other == this) {
    return *this;
  }

  values_.clear();
  values_.swap(other.values_);
  return *this;
}

Tuple::~Tuple() {
}

// add (Value && value)
void Tuple::add(TupleValue *value) {
  values_.emplace_back(value);
}
void Tuple::add(const std::shared_ptr<TupleValue> &other) {
  values_.emplace_back(other);
}
void Tuple::add(int value) {
  add(new IntValue(value));
}

void Tuple::add(float value) {
  add(new FloatValue(value));
}

void Tuple::add(const char *s, int len) {
  add(new StringValue(s, len));
}

void Tuple::append(const Tuple &other){
  values_.reserve(values_.size() + other.size());
  for(size_t i=0; i<other.size(); i++){
    add(other.get_pointer(i));
  }
}

void Tuple::set(int index, const std::shared_ptr<TupleValue> value){
  values_[index] = value;
}

void Tuple::set_size(int size){
  values_.reserve(size);
  for(int i=0;i<size;i++) values_.push_back(nullptr);
}

////////////////////////////////////////////////////////////////////////////////

std::string TupleField::to_string() const {
  return std::string(table_name_) + "." + field_name_ + std::to_string(type_);
}

////////////////////////////////////////////////////////////////////////////////
void TupleSchema::from_table(const Table *table, TupleSchema &schema) {
  const char *table_name = table->name();
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = 0; i < field_num; i++) {
    const FieldMeta *field_meta = table_meta.field(i);
    if (field_meta->visible()) {
      schema.add(field_meta->type(), table_name, field_meta->name());
    }
  }
}

void TupleSchema::add(AttrType type, const char *table_name, const char *field_name, int aggregate_type) {
  fields_.emplace_back(type, table_name, field_name, aggregate_type);
}

void TupleSchema::add_if_not_exists(AttrType type, const char *table_name, const char *field_name) {
  for (const auto &field: fields_) {
    if (0 == strcmp(field.table_name(), table_name) &&
        0 == strcmp(field.field_name(), field_name)) {
      return;
    }
  }

  add(type, table_name, field_name);
}

void TupleSchema::append(const TupleSchema &other) {
  fields_.reserve(fields_.size() + other.fields_.size());
  for (const auto &field: other.fields_) {
    fields_.emplace_back(field);
  }
}

int TupleSchema::index_of_field(const char *table_name, const char *field_name) const {
  const int size = fields_.size();
  for (int i = 0; i < size; i++) {
    const TupleField &field = fields_[i];
    if (0 == strcmp(field.table_name(), table_name) && 0 == strcmp(field.field_name(), field_name)) {
      return i;
    }
  }
  return -1;
}

void TupleSchema::print(std::ostream &os, bool single) const {
  static char agg_out[5][10] = {" ", "min", "max", "avg", "count"};

  if (fields_.empty()) {
    os << "No schema";
    return;
  }

  for (std::vector<TupleField>::const_iterator iter = fields_.begin(), end = --fields_.end();
       iter != end; ++iter) {
    if(iter->agg_type()){
      os << agg_out[iter->agg_type()] << "(";
      if(!strcmp(iter->table_name(),"*")){
        os << "*)";
        os << " | ";
        continue;
      }
    }
    if (!single) {
      os << iter->table_name() << ".";
    }
    os << iter->field_name();
    if(iter->agg_type()) os << ")";
    os << " | ";
  }
  if(fields_.back().agg_type()){
    os << agg_out[fields_.back().agg_type()] << "(";
    if(!strcmp(fields_.back().table_name(),"*")){
      os << "*)";
      os << std::endl;
      return;
    }
  }
  if (!single) {
    os << fields_.back().table_name() << ".";
  }
  os << fields_.back().field_name();
  if(fields_.back().agg_type()) os << ")";
  os << std::endl;
}

/////////////////////////////////////////////////////////////////////////////
TupleSet::TupleSet(TupleSet &&other) : tuples_(std::move(other.tuples_)), schema_(other.schema_){
  other.schema_.clear();
}

TupleSet &TupleSet::operator=(TupleSet &&other) {
  if (this == &other) {
    return *this;
  }

  schema_.clear();
  schema_.append(other.schema_);
  other.schema_.clear();

  tuples_.clear();
  tuples_.swap(other.tuples_);
  return *this;
}

void TupleSet::add(Tuple &&tuple) {
  tuples_.emplace_back(std::move(tuple));
}


void TupleSet::clear() {
  tuples_.clear();
  schema_.clear();
}

void TupleSet::print(std::ostream &os, bool single) const {
  if (schema_.fields().empty()) {
    LOG_WARN("Got empty schema");
    return;
  }

  schema_.print(os, single);

  for (const Tuple &item : tuples_) {
    const std::vector<std::shared_ptr<TupleValue>> &values = item.values();
    int field_pos = -1;
    for (std::vector<std::shared_ptr<TupleValue>>::const_iterator iter = values.begin(), end = --values.end(); iter != end; ++iter) {
      AttrType attr_type = schema_.field(++field_pos).type();
      if(attr_type == DATES){
        int value = *(int*)((*iter)->value());
        char buf[16] = {0};
        snprintf(buf,sizeof(buf),"%04d-%02d-%02d",value/10000,(value%10000)/100,value%100); 
        os << std::string(buf);
      }
      else (*iter)->to_string(os);
      os << " | ";   
    }
    AttrType attr_type = schema_.fields().back().type();
    if(attr_type == DATES){
      int value = *(int*)((*(values.back())).value());
      char buf[16] = {0};
      snprintf(buf,sizeof(buf),"%04d-%02d-%02d",value/10000,(value%10000)/100,value%100); 
      os << std::string(buf);
    }
    else values.back()->to_string(os);
    os << std::endl;
  }
}

void TupleSet::set_schema(const TupleSchema &schema) {
  schema_ = schema;
}

void TupleSet::swap_line(int a, int b){
  std::swap(tuples_[a], tuples_[b]);
}


void TupleSet::set(int row, int col, const std::shared_ptr<TupleValue> value){
  tuples_[row].set(col, value);
}

const TupleSchema &TupleSet::get_schema() const {
  return schema_;
}

bool TupleSet::is_empty() const {
  return tuples_.empty();
}

int TupleSet::size() const {
  return tuples_.size();
}

const Tuple &TupleSet::get(int index) const {
  return tuples_[index];
}

void TupleSet::erase_col(int col){
  for(int i=0; i<tuples_.size(); i++){
    tuples_[i].erase(col);
  }
  schema_.erase(col);
}

const std::vector<Tuple> &TupleSet::tuples() const {
  return tuples_;
}



/////////////////////////////////////////////////////////////////////////////
TupleRecordConverter::TupleRecordConverter(Table *table, TupleSet &tuple_set) :
      table_(table), tuple_set_(tuple_set){
}

void TupleRecordConverter::add_record(const char *record) {
  const TupleSchema &schema = tuple_set_.schema();
  Tuple tuple;
  const TableMeta &table_meta = table_->table_meta();
  for (const TupleField &field : schema.fields()) {
    const FieldMeta *field_meta = table_meta.field(field.field_name());
    assert(field_meta != nullptr);
    switch (field_meta->type()) {
      case DATES:
      case INTS: {
        int value = *(int*)(record + field_meta->offset());
        tuple.add(value);
      }
      break;
      case FLOATS: {
        float value = *(float *)(record + field_meta->offset());
        tuple.add(value);
      }
        break;
      case CHARS: {
        const char *s = record + field_meta->offset();  // ????????????Cstring?????????
        tuple.add(s, strlen(s));
      }
      break;
      default: {
        LOG_PANIC("Unsupported field type. type=%d", field_meta->type());
      }
    }
  }

  tuple_set_.add(std::move(tuple));
}


