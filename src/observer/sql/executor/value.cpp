/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#include "sql/executor/value.h"

std::shared_ptr<TupleValue> get_tuple_value(void* data, AttrType attr_type){
  TupleValue *ret;
  switch(attr_type){
    case INTS:
    case DATES:
      ret = new IntValue(*((int*)data)); break;
    case FLOATS:
      ret = new FloatValue(*((float*)data)); break;
    case CHARS:
      ret = new StringValue((char*)data); break;
  }
  return std::shared_ptr<TupleValue>(ret->get_pointer());
}

const std::shared_ptr<TupleValue> IntValue::compute(int agg_type, const std::shared_ptr<TupleValue> other){
  if(agg_type == MIN_AGG){
    if( !other || compare(*other)<0) return std::shared_ptr<TupleValue>(nullptr);
    return other;
  }
  if(agg_type == MAX_AGG){
    if( !other || compare(*other)>0) return std::shared_ptr<TupleValue>(nullptr);
    return other;
  }
  if(agg_type == AVG_AGG){
    float sum = value_;
    if(other) sum += *(float*)other->value();
    return std::shared_ptr<TupleValue>(new FloatValue(sum));
  }
  if(agg_type == CNT_AGG){
    int cnt = 1;
    if(other) cnt += *(int*)other->value();
    return std::shared_ptr<TupleValue>(new IntValue(cnt));
  }
  return std::shared_ptr<TupleValue>(nullptr);
}


const std::shared_ptr<TupleValue> FloatValue::compute(int agg_type, const std::shared_ptr<TupleValue> other){
  if(agg_type == MIN_AGG){
    if( !other || compare(*other)<0) return std::shared_ptr<TupleValue>(nullptr);
    return other;
  }
  if(agg_type == MAX_AGG){
    if( !other || compare(*other)>0) return std::shared_ptr<TupleValue>(nullptr);
    return other;
  }
  if(agg_type == AVG_AGG){
    float sum = value_;
    if(other) sum += *(float*)other->value();
    return std::shared_ptr<TupleValue>(new FloatValue(sum));
  }
  if(agg_type == CNT_AGG){
    int cnt = 1;
    if(other) cnt += *(int*)other->value();
    return std::shared_ptr<TupleValue>(new IntValue(cnt));
  }
  float cnt = *(int*)other->value();
  cnt = value_/cnt;
  return std::shared_ptr<TupleValue>(new FloatValue(cnt));
}


const std::shared_ptr<TupleValue> StringValue::compute(int agg_type, const std::shared_ptr<TupleValue> other){
  if(agg_type == MIN_AGG){
    if( !other || compare(*other)<0) return std::shared_ptr<TupleValue>(nullptr);
    return other;
  }
  if(agg_type == MAX_AGG){
    if( !other || compare(*other)>0) return std::shared_ptr<TupleValue>(nullptr);
    return other;
  }
  if(agg_type == AVG_AGG){
    return std::shared_ptr<TupleValue>(nullptr);
  }
  if(agg_type == CNT_AGG){
    int cnt = 1;
    if(other) cnt += *(int*)other->value();
    return std::shared_ptr<TupleValue>(new IntValue(cnt));
  }
  return std::shared_ptr<TupleValue>(nullptr);
}