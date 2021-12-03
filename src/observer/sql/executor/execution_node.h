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
// Created by Wangyunlai on 2021/5/13.
//

#ifndef __OBSERVER_SQL_EXECUTOR_EXECUTION_NODE_H_
#define __OBSERVER_SQL_EXECUTOR_EXECUTION_NODE_H_

#include <vector>
#include <set>
#include <memory>
#include "common/lang/bitmap.h"
#include "storage/common/condition_filter.h"
#include "sql/executor/tuple.h"
#include "sql/parser/parse_defs.h"

#define MAP_BIT_CONDITION 64

class Table;
class Trx;

class ExecutionNode {
public:
  ExecutionNode() = default;
  virtual ~ExecutionNode() = default;

  virtual RC execute(TupleSet &tuple_set) = 0;
};

class SelectExeNode : public ExecutionNode {
public:
  SelectExeNode();
  virtual ~SelectExeNode();

  RC init(Trx *trx, Table *table, TupleSchema && tuple_schema, std::vector<DefaultConditionFilter *> &&condition_filters);

  RC execute(TupleSet &tuple_set) override;
private:
  Trx *trx_ = nullptr;
  Table  * table_;
  TupleSchema  tuple_schema_;
  std::vector<DefaultConditionFilter *> condition_filters_;
};


class TableSelectNode{
  public:
    TableSelectNode() = default;
    ~TableSelectNode(){
      trx_ = nullptr;
      table_ = nullptr;
      filter_ = nullptr;
      printf("here\n");
    };

    RC init(Trx *trx, Table *table, CompositeConditionFilter *condition_filter);

    RC execute(TupleSet *tuple_set);

private:
  Trx *trx_ = nullptr;
  Table  * table_ = nullptr;
  CompositeConditionFilter *filter_ = nullptr;
  //ConditionFilter *filter_ = nullptr;
  CompositeConditionFilter null_filter_;
};


class SelectExpand{
  public:
    SelectExpand(Trx *trx, int condition_num, Condition* conditions): trx_(trx), condition_num_(condition_num), conditions_(conditions){
    }

    ~SelectExpand() = default;
    void check_contain(TupleSet *main_set, TupleSet *follow_set, int condition_id);

    TupleSet * execute(TupleSet *main_set, TupleSet *follow_set);

    CompositeConditionFilter *assign(int main_tuple_id, TupleSet *main_set, TupleSet *follow_set);

    RC filter(int main_row, TupleSet *main_set, TupleSet *follow_set, TupleSet *new_main, CompositeConditionFilter *comp_filter);


  private:
    Trx *trx_ = nullptr;
    int condition_num_ = 0;
    Condition* conditions_ = nullptr;
    bool done_ = false;
    int num_ = 0;

    bool single_ = false;
    std::vector<int> indexes;
};

#endif //__OBSERVER_SQL_EXECUTOR_EXECUTION_NODE_H_
