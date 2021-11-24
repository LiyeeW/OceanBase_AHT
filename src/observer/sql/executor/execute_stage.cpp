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
// Created by Longda on 2021/4/13.
//

#include <string>
#include <sstream>

#include "execute_stage.h"

#include "common/io/io.h"
#include "common/log/log.h"
#include "common/seda/timer_stage.h"
#include "common/lang/string.h"
#include "session/session.h"
#include "event/storage_event.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "event/execution_plan_event.h"
#include "sql/executor/execution_node.h"
#include "sql/executor/tuple.h"
#include "storage/common/table.h"
#include "storage/default/default_handler.h"
#include "storage/common/condition_filter.h"
#include "storage/trx/trx.h"

using namespace common;

RC create_selection_executor(Trx *trx, const Selects &selects, const char *db, const char *table_name, SelectExeNode &select_node);

//! Constructor
ExecuteStage::ExecuteStage(const char *tag) : Stage(tag) {}

//! Destructor
ExecuteStage::~ExecuteStage() {}

//! Parse properties, instantiate a stage object
Stage *ExecuteStage::make_stage(const std::string &tag) {
  ExecuteStage *stage = new (std::nothrow) ExecuteStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new ExecuteStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

//! Set properties for this object set in stage specific properties
bool ExecuteStage::set_properties() {
  //  std::string stageNameStr(stageName);
  //  std::map<std::string, std::string> section = theGlobalProperties()->get(
  //    stageNameStr);
  //
  //  std::map<std::string, std::string>::iterator it;
  //
  //  std::string key;

  return true;
}

//! Initialize stage params and validate outputs
bool ExecuteStage::initialize() {
  LOG_TRACE("Enter");

  std::list<Stage *>::iterator stgp = next_stage_list_.begin();
  default_storage_stage_ = *(stgp++);
  mem_storage_stage_ = *(stgp++);

  LOG_TRACE("Exit");
  return true;
}

//! Cleanup after disconnection
void ExecuteStage::cleanup() {
  LOG_TRACE("Enter");

  LOG_TRACE("Exit");
}

void ExecuteStage::handle_event(StageEvent *event) {
  LOG_TRACE("Enter\n");

  handle_request(event);

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::callback_event(StageEvent *event, CallbackContext *context) {
  LOG_TRACE("Enter\n");

  // here finish read all data from disk or network, but do nothing here.
  ExecutionPlanEvent *exe_event = static_cast<ExecutionPlanEvent *>(event);
  SQLStageEvent *sql_event = exe_event->sql_event();
  sql_event->done_immediate();

  LOG_TRACE("Exit\n");
  return;
}

void end_trx_if_need(Session *session, Trx *trx, bool all_right) {
  if (!session->is_trx_multi_operation_mode()) {
    if (all_right) {
      trx->commit();
    } else {
      trx->rollback();
    }
  }
}

void ExecuteStage::handle_request(common::StageEvent *event) {
  ExecutionPlanEvent *exe_event = static_cast<ExecutionPlanEvent *>(event);
  SessionEvent *session_event = exe_event->sql_event()->session_event();
  Query *sql = exe_event->sqls();
  const char *current_db = session_event->get_client()->session->get_current_db().c_str();
  Session *session = session_event->get_client()->session;
  Trx *trx = session->current_trx();

  CompletionCallback *cb = new (std::nothrow) CompletionCallback(this, nullptr);
  if (cb == nullptr) {
    LOG_ERROR("Failed to new callback for ExecutionPlanEvent");
    exe_event->done_immediate();
    return;
  }
  exe_event->push_callback(cb);
  RC rc = semantic_check(current_db, sql);
  if(rc != RC::SUCCESS){
    LOG_INFO("Semantic error");
    end_trx_if_need(session, trx, false);
    session_event->set_response("FAILURE\n");
    exe_event->done_immediate();
    return ;
  }

  switch (sql->flag) {
    case SCF_SELECT: { // select
      do_select(current_db, sql, exe_event->sql_event()->session_event());
      exe_event->done_immediate();
    }
    break;

    case SCF_INSERT:
    case SCF_UPDATE:
    case SCF_DELETE:
    case SCF_CREATE_TABLE:
    case SCF_SHOW_TABLES:
    case SCF_DESC_TABLE:
    case SCF_DROP_TABLE:
    case SCF_CREATE_INDEX:
    case SCF_DROP_INDEX: 
    case SCF_LOAD_DATA: {
      StorageEvent *storage_event = new (std::nothrow) StorageEvent(exe_event);
      if (storage_event == nullptr) {
        LOG_ERROR("Failed to new StorageEvent");
        event->done_immediate();
        return;
      }

      default_storage_stage_->handle_event(storage_event);
    }
    break;
    case SCF_SYNC: {
      RC rc = DefaultHandler::get_default().sync();
      session_event->set_response(strrc(rc));
      exe_event->done_immediate();
    }
    break;
    case SCF_BEGIN: {
      session_event->get_client()->session->set_trx_multi_operation_mode(true);
      session_event->set_response(strrc(RC::SUCCESS));
      exe_event->done_immediate();
    }
    break;
    case SCF_COMMIT: {
      Trx *trx = session_event->get_client()->session->current_trx();
      RC rc = trx->commit();
      session_event->get_client()->session->set_trx_multi_operation_mode(false);
      session_event->set_response(strrc(rc));
      exe_event->done_immediate();
    }
    break;
    case SCF_ROLLBACK: {
      Trx *trx = session_event->get_client()->session->current_trx();
      RC rc = trx->rollback();
      session_event->get_client()->session->set_trx_multi_operation_mode(false);
      session_event->set_response(strrc(rc));
      exe_event->done_immediate();
    }
    break;
    case SCF_HELP: {
      const char *response = "show tables;\n"
          "desc `table name`;\n"
          "create table `table name` (`column name` `column type`, ...);\n"
          "create index `index name` on `table` (`column`);\n"
          "insert into `table` values(`value1`,`value2`);\n"
          "update `table` set column=value [where `column`=`value`];\n"
          "delete from `table` [where `column`=`value`];\n"
          "select [ * | `columns` ] from `table`;\n";
      session_event->set_response(response);
      exe_event->done_immediate();
    }
    break;
    case SCF_EXIT: {
      // do nothing
      const char *response = "Unsupported\n";
      session_event->set_response(response);
      exe_event->done_immediate();
    }
    break;
    default: {
      exe_event->done_immediate();
      LOG_ERROR("Unsupported command=%d\n", sql->flag);
    }
  }
}


bool condition_classify(const char *db, size_t condition_num, Condition *conditions, 
        std::unordered_map<std::string, CompositeConditionFilter*> &table_filters){

  std::unordered_map<std::string, std::vector<DefaultConditionFilter *>> table_defaults;
  std::vector<DefaultConditionFilter *> vector_defaults;
  table_defaults["*"] = vector_defaults;
  
  for (size_t i = 0; i < condition_num; i++) {
    Condition &condition = conditions[i];
    DefaultConditionFilter *condition_filter = new DefaultConditionFilter();
    
    if(condition.left_is_attr == 0 && condition.right_is_attr == 0){
      //const init
      condition_filter->init(condition);
      table_defaults["*"].push_back(condition_filter);
      condition.flag = 0;
    }

    else if((condition.left_is_attr == 1 && condition.right_is_attr == 0 ) ||  
        (condition.left_is_attr == 0 && condition.right_is_attr == 1 )){
      // push_filter
      char *table_name = (condition.left_is_attr)? condition.left_attr.relation_name : condition.right_attr.relation_name;
      Table *table =  DefaultHandler::get_default().find_table(db, table_name);
      condition_filter->init(*table, condition);
      std::string name_str = table_name;
      if(table_defaults.count(name_str) == 0)
        table_defaults[name_str] = vector_defaults;
      table_defaults[name_str].push_back(condition_filter);
      condition.flag = 0;
    }
    else{
      condition.flag = 2;
    };
  }

  for(auto outer_iter : table_defaults){
    CompositeConditionFilter *condition_filter = new CompositeConditionFilter();
    condition_filter->init((const ConditionFilter **)outer_iter.second.data(), outer_iter.second.size());
    if(outer_iter.first == "*"){
      if(false == condition_filter->filter()) return true;
    }
    else{
      table_filters[outer_iter.first] = condition_filter;
    }
  }

  return false;
}



RC ExecuteStage::do_select(const char *db, Query *sql, SessionEvent *session_event) {

  RC rc = RC::SUCCESS;
  Session *session = session_event->get_client()->session;
  Trx *trx = session->current_trx();
  Selects &selects = sql->sstr.selection;
  if (selects.relation_num < 1) {
    LOG_ERROR("No table given");
    end_trx_if_need(session, trx, false);
    return RC::SQL_SYNTAX;
  }

  // where condition classify
  std::unordered_map<std::string, CompositeConditionFilter*> table_filters;
  bool is_false = condition_classify(db, selects.condition_num, selects.conditions, table_filters);
  if(is_false){
    //print_final_schema TODO 
    return rc;
  }

  //expand
  TupleSet *main_tupleset;
  bool first = true;
  for (int i = selects.relation_num-1; i >=0 ; i--){
    printf("%d\n", i);
    CompositeConditionFilter *condition_filter = nullptr;
    if(table_filters.count(std::string(selects.relations[i])))
        condition_filter = table_filters[std::string(selects.relations[i])];
    TableSelectNode table_select_node;
    table_select_node.init(trx, DefaultHandler::get_default().find_table(db, selects.relations[i]), condition_filter);
    TupleSet *follow_tupleset = new TupleSet();
    table_select_node.execute(follow_tupleset);
    if(first){
      first = false;
      main_tupleset = follow_tupleset;
    }
    else{
      SelectExpand select_expand(trx, selects.condition_num, selects.conditions);
      TupleSet *new_main = select_expand.execute(main_tupleset, follow_tupleset);
      main_tupleset = new_main;
    }
  }

  //final schema
  TupleSchema tuple_schema;
  for (int i = selects.attr_num - 1; i >= 0; i--) {
    const RelAttr &attr = selects.attributes[i];
    if (0 == strcmp("*", attr.attribute_name)) {
      if(NULL == attr.relation_name){
        if(selects.attr_num > 1) return RC::GENERIC_ERROR;
        //all table
        for(int j=selects.relation_num-1; j>=0; j--){
          TupleSchema::from_table(DefaultHandler::get_default().find_table(db, selects.relations[j]), tuple_schema);
        }
      }
      else TupleSchema::from_table(DefaultHandler::get_default().find_table(db, attr.relation_name), tuple_schema);
    } 
    else {
      AttrType attr_type = DefaultHandler::get_default().find_table(db, attr.relation_name)->table_meta().field(attr.attribute_name)->type();
      tuple_schema.add(attr_type, attr.relation_name?attr.relation_name:selects.relations[0], attr.attribute_name);
    }
  }

  //final select of attrs
  TupleSet *result_tuple_set = new TupleSet();
  result_tuple_set->set_schema(tuple_schema);
  for(int i=0; i<main_tupleset->size(); i++){
    Tuple tuple;
    for(const auto &field: result_tuple_set->get_schema().fields()){
      int pos = main_tupleset->get_schema().index_of_field(field.table_name(), field.field_name());
      tuple.add(main_tupleset->get(i).get_pointer(pos));
    }
    result_tuple_set->add(std::move(tuple));
  }

  //output
  std::stringstream ss;
  result_tuple_set->print(ss);

  session_event->set_response(ss.str());
  end_trx_if_need(session, trx, true);
  return rc;
}



RC ExecuteStage::semantic_check(const char *db, Query *sql){
  std::unordered_map<std::string, std::vector<std::string>> table_attrs;
  std::string table_name, attr_name, temp_table; 
  std::vector<std::string> attrs;
  const Condition* condition;
  size_t condition_num=0;
  bool multi = false;
  switch (sql->flag) {
    case SCF_SELECT: {
      const Selects &selects = sql->sstr.selection;
      for(size_t i = 0; i < selects.relation_num; i++){
        table_name = selects.relations[i];
        table_attrs[table_name] = attrs;
      }
      condition = selects.conditions;
      condition_num = selects.condition_num;      
      if(selects.relation_num>1) multi = true;
      for(size_t i = 0; i < selects.attr_num; i++){        
        if(selects.attributes[i].relation_name == NULL){
          attr_name = selects.attributes[i].attribute_name;
          if(attr_name == "*") return RC::SUCCESS;
          if(multi) return RC::GENERIC_ERROR;
          temp_table = table_name;
        }
        else{
          temp_table = selects.attributes[i].relation_name;
          if(!table_attrs.count(temp_table)) 
            return RC::GENERIC_ERROR; 
        }       
        attr_name = selects.attributes[i].attribute_name;
        if(attr_name != "*"){
          table_attrs[temp_table].push_back(attr_name);
        }
      }
    }
    break;

    case SCF_INSERT:{
      const Inserts &inserts = sql->sstr.insertion;
      table_name = inserts.relation_name;
      table_attrs[table_name] = attrs;
    }
    break;

    case SCF_UPDATE:{
      const Updates &updates = sql->sstr.update;
      table_name = updates.relation_name;
      table_attrs[table_name] = attrs;
      condition = updates.conditions;
      condition_num = updates.condition_num;
      table_attrs[table_name].push_back(std::string(updates.attribute_name));
    }
    break;

    case SCF_DELETE:{
      const Deletes &deletes = sql->sstr.deletion;
      table_name = deletes.relation_name;
      table_attrs[table_name] = attrs;
      condition = deletes.conditions;
      condition_num = deletes.condition_num;
    }
    break;

    default: 
      return RC::SUCCESS;
  }

  for(size_t i=0; i<condition_num; i++){
    if(condition[i].left_is_attr){
      if(condition[i].left_attr.relation_name == NULL){
        if(multi) return RC::GENERIC_ERROR;
        temp_table = table_name;
      }
      else{
        temp_table = condition[i].left_attr.relation_name;
        if(!table_attrs.count(temp_table)) return RC::GENERIC_ERROR;       
      }  
      attr_name = condition[i].left_attr.attribute_name;
      if(attr_name != "*"){
        table_attrs[temp_table].push_back(attr_name);
      }
    }
    if(condition[i].right_is_attr){
      if(condition[i].right_attr.relation_name == NULL){
        if(multi) return RC::GENERIC_ERROR;
        temp_table = table_name;
      }
      else{
        temp_table = condition[i].right_attr.relation_name;
        if(!table_attrs.count(temp_table)) return RC::GENERIC_ERROR;       
      }      
      attr_name = condition[i].right_attr.attribute_name;
      if(attr_name != "*"){
        table_attrs[temp_table].push_back(attr_name);
      }
    }
  }
  //check tables
  Table *tbl;
  for(auto outer_iter: table_attrs){
    tbl = DefaultHandler::get_default().find_table(db, outer_iter.first.c_str());
    if(tbl == nullptr) return RC::GENERIC_ERROR;
    for(auto inner_iter: outer_iter.second){
      if(tbl->table_meta().field(inner_iter.c_str()) == nullptr) 
        return RC::GENERIC_ERROR;
    }
  }
  return RC::SUCCESS;
}

