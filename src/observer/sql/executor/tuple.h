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

#ifndef __OBSERVER_SQL_EXECUTOR_TUPLE_H_
#define __OBSERVER_SQL_EXECUTOR_TUPLE_H_

#include <memory>
#include <vector>
#include <set>
#include <algorithm>

#include "sql/parser/parse.h"
#include "sql/executor/value.h"
#include <cstdio>

class Table;

class Tuple {
public:
  Tuple() = default;

  Tuple(const Tuple &other);

  ~Tuple();

  Tuple(Tuple &&other) noexcept ;
  Tuple & operator=(Tuple &&other) noexcept ;

  void add(TupleValue *value);
  void add(const std::shared_ptr<TupleValue> &other);
  void add(int value);
  void add(float value);
  void add(const char *s, int len);
  void append(const Tuple &other);
  void set(int index, const std::shared_ptr<TupleValue> value);
  void set_size(int size);

  void erase(int col){
    values_.erase(values_.begin()+col);
  }

  const std::vector<std::shared_ptr<TupleValue>> &values() const {
    return values_;
  }

  int size() const {
    return values_.size();
  }

  const TupleValue &get(int index) const {
    return *values_[index];
  }

  const std::shared_ptr<TupleValue> &get_pointer(int index) const {
    return values_[index];
  }

private:
  std::vector<std::shared_ptr<TupleValue>>  values_;
};

class TupleField {
public:
  TupleField(AttrType type, const char *table_name, const char *field_name, int aggregate_type) :
          type_(type), table_name_(table_name), field_name_(field_name), aggregate_type_(aggregate_type){
  }

  AttrType  type() const{
    return type_;
  }

  const char *table_name() const {
    return table_name_.c_str();
  }
  const char *field_name() const {
    return field_name_.c_str();
  }

  const int agg_type() const {
    return aggregate_type_;
  }

  std::string to_string() const;
private:
  AttrType  type_;
  std::string table_name_;
  std::string field_name_;
  int aggregate_type_;
};

class TupleSchema {
public:
  TupleSchema() = default;
  ~TupleSchema() = default;

  void add(AttrType type, const char *table_name, const char *field_name, int aggregate_type = NON_AGG);
  void add_if_not_exists(AttrType type, const char *table_name, const char *field_name);
  // void merge(const TupleSchema &other);
  void append(const TupleSchema &other);

  void erase(int col){
    fields_.erase(fields_.begin()+col);
  }

  const std::vector<TupleField> &fields() const {
    return fields_;
  }

  const TupleField &field(int index) const {
    return fields_[index];
  }

  int index_of_field(const char *table_name, const char *field_name) const;
  void clear() {
    fields_.clear();
  }

  void print(std::ostream &os, bool single) const;
public:
  static void from_table(const Table *table, TupleSchema &schema);
private:
  std::vector<TupleField> fields_;
};

class TupleSet {
public:
  TupleSet() = default;
  TupleSet(TupleSet &&other);
  explicit TupleSet(const TupleSchema &schema) : schema_(schema) {
  }
  TupleSet &operator =(TupleSet &&other);

  ~TupleSet(){
    printf("~ TupleSet here\n");
  }

  void set_schema(const TupleSchema &schema);

  void erase_col(int col);

  const TupleSchema &get_schema() const;

  void add(Tuple && tuple);
  void swap_line(int a, int b);

  void clear();
  void set(int row, int col, const std::shared_ptr<TupleValue> value);

  bool is_empty() const;
  int size() const;
  const Tuple &get(int index) const;
  const std::vector<Tuple> &tuples() const;

  void print(std::ostream &os, bool single) const;

public:
  const TupleSchema &schema() const {
    return schema_;
  }
private:
  std::vector<Tuple> tuples_;
  TupleSchema schema_;
};

class TupleRecordConverter {
public:
  TupleRecordConverter(Table *table, TupleSet &tuple_set);

  void add_record(const char *record);
private:
  Table *table_;
  TupleSet &tuple_set_;
};

#endif //__OBSERVER_SQL_EXECUTOR_TUPLE_H_
