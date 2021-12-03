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

#include "sql/executor/execution_node.h"
#include "storage/common/table.h"
#include "common/log/log.h"

SelectExeNode::SelectExeNode() : table_(nullptr) {
}

SelectExeNode::~SelectExeNode() {
  for (DefaultConditionFilter * &filter : condition_filters_) {
    delete filter;
  }
  condition_filters_.clear();
}

RC
SelectExeNode::init(Trx *trx, Table *table, TupleSchema &&tuple_schema, std::vector<DefaultConditionFilter *> &&condition_filters) {
  trx_ = trx;
  table_ = table;
  tuple_schema_ = tuple_schema;
  condition_filters_ = std::move(condition_filters);
  return RC::SUCCESS;
}

void record_reader(const char *data, void *context) {
  TupleRecordConverter *converter = (TupleRecordConverter *)context;
  converter->add_record(data);
}
RC SelectExeNode::execute(TupleSet &tuple_set) {
  CompositeConditionFilter condition_filter;
  condition_filter.init((const ConditionFilter **)condition_filters_.data(), condition_filters_.size());

  tuple_set.clear();
  tuple_set.set_schema(tuple_schema_);
  TupleRecordConverter converter(table_, tuple_set);
  return table_->scan_record(trx_, &condition_filter, -1, (void *)&converter, record_reader);
}

/////////////////////////////////////////////
RC TableSelectNode::init(Trx *trx, Table *table, CompositeConditionFilter *condition_filter){
  trx_ = trx;
  table_ = table;
  filter_ = condition_filter;
  if(filter_ == nullptr){
    filter_ = &null_filter_;
  }
  return RC::SUCCESS;
}

RC TableSelectNode::execute(TupleSet *tuple_set){
  tuple_set->clear();
  TupleSchema *tuple_schema = new TupleSchema();
  TupleSchema::from_table(table_, *tuple_schema);
  tuple_set->set_schema(*tuple_schema);
  TupleRecordConverter converter(table_, *tuple_set);
  return table_->scan_record(trx_, filter_, -1, (void *)&converter, record_reader);
}


//////////////////////////////////////////
void SelectExpand::check_contain(TupleSet *main_set, TupleSet *follow_set, int condition_id){
  Condition &c = conditions_[condition_id];
  bool left_ok = !(c.left_is_attr);
  bool right_ok = !(c.right_is_attr);
  left_ok |= main_set->get_schema().index_of_field(c.left_attr.relation_name, c.left_attr.attribute_name) != -1;
  left_ok |= follow_set->get_schema().index_of_field(c.left_attr.relation_name, c.left_attr.attribute_name) != -1;
  right_ok |= main_set->get_schema().index_of_field(c.right_attr.relation_name, c.right_attr.attribute_name) != -1;
  right_ok |= follow_set->get_schema().index_of_field(c.right_attr.relation_name, c.right_attr.attribute_name) != -1;

  if(left_ok && right_ok){
    num_++;
    c.flag = 1;
  }
}


TupleSet * SelectExpand::execute(TupleSet *main_set, TupleSet *follow_set){
  // find and mark exited multi-condition as 1
  num_ = 0;
  for(int i=0; i<condition_num_ && !done_; i++){
    if(conditions_[i].flag != 0) check_contain(main_set, follow_set, i);
  }
  if(!num_) done_ = true;

  //new schema
  TupleSet *new_main = new TupleSet();
  TupleSchema *new_schema = new TupleSchema();
  new_schema->append(main_set->get_schema());
  new_schema->append(follow_set->get_schema());
  new_main->set_schema(*new_schema);

  //filter and product
  for(size_t i=0; i<(main_set->size()); i++){
    CompositeConditionFilter *comp_filter = assign(i, main_set, follow_set);
    filter(i, main_set, follow_set, new_main, comp_filter);
    delete comp_filter;
  }

  //cancel marked multi-condition
  for(int i=0; i<condition_num_ && !done_; i++){
    if(conditions_[i].flag == 1){
      conditions_[i].flag = 0;
    }
  }

  delete main_set;
  delete follow_set;
  return new_main;
}

CompositeConditionFilter * SelectExpand::assign(int main_tuple_id, TupleSet *main_set, TupleSet *follow_set){
  CompositeConditionFilter *comp_filter = new CompositeConditionFilter();
  if(done_){
    comp_filter->init((const ConditionFilter **)nullptr, 0);
    return comp_filter;
  }
  ConditionFilter **condition_filters = new ConditionFilter *[num_];
  int cid = 0;

  for(int i=0; i<condition_num_; i++){
    if(conditions_[i].flag != 1) continue;

    ConDesc  left;
    ConDesc  right;
    AttrType com_type;
    DefaultConditionFilter *temp_filter = new DefaultConditionFilter();

    if(conditions_[i].left_is_attr){
      int field_pos = main_set->get_schema().index_of_field(conditions_[i].left_attr.relation_name, conditions_[i].left_attr.attribute_name);
        
      if(field_pos != -1){
        com_type = main_set->get_schema().field(field_pos).type();
        left.is_attr = false;
        left.value = main_set->get(main_tuple_id).get(field_pos).value();
      }
      else{
        left.is_attr = true;
        left.attr_offset = follow_set->get_schema().index_of_field(conditions_[i].left_attr.relation_name, conditions_[i].left_attr.attribute_name);
        com_type = main_set->get_schema().field(left.attr_offset).type();
      }
    }
    else{
      com_type = conditions_[i].left_value.type;
      left.is_attr = false;
      left.value = conditions_[i].left_value.data;
    }

    if(conditions_[i].right_is_attr){
      int field_pos = main_set->get_schema().index_of_field(conditions_[i].right_attr.relation_name, conditions_[i].right_attr.attribute_name);
        
      if(field_pos != -1){
        right.is_attr = false;
        right.value = main_set->get(main_tuple_id).get(field_pos).value();
      }
      else{
        right.is_attr = true;
        right.attr_offset = follow_set->get_schema().index_of_field(conditions_[i].right_attr.relation_name, conditions_[i].right_attr.attribute_name);
      }
    }
    else{
      right.is_attr = false;
      right.value = conditions_[i].right_value.data;
    }
    
    ///check type
    temp_filter->init(left, right, com_type, conditions_[i].comp);
    condition_filters[cid++] = temp_filter;
  }
  comp_filter->init((const ConditionFilter **)condition_filters, num_);
  return comp_filter;
}


RC SelectExpand::filter(int main_row, TupleSet *main_set, TupleSet *follow_set, TupleSet *new_main, CompositeConditionFilter *comp_filter){
  for(size_t i=0; i<follow_set->size(); i++){
    if(comp_filter->filter(follow_set->get(i))){
      Tuple temp_tuple;
      temp_tuple.append(main_set->get(main_row));
      temp_tuple.append(follow_set->get(i));
      new_main->add(std::move(temp_tuple));
    }
  }
  return RC::SUCCESS;
}
