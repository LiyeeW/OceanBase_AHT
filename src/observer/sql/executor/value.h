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

#ifndef __OBSERVER_SQL_EXECUTOR_VALUE_H_
#define __OBSERVER_SQL_EXECUTOR_VALUE_H_

#include <string.h>
#include <memory>
#include <string>
#include <ostream>
#include "sql/parser/parse.h"
#include "sql/parser/parse_defs.h"

class FloatValue;

class TupleValue {
public:
  TupleValue() = default;
  virtual ~TupleValue() = default;

  virtual void to_string(std::ostream &os) const = 0;
  virtual int compare(const TupleValue &other) const = 0;
  virtual void* value() const = 0;
  virtual TupleValue* get_pointer() = 0;
  virtual const std::shared_ptr<TupleValue> compute(int agg_type, const std::shared_ptr<TupleValue> other) = 0;
private:
};

class IntValue : public TupleValue {
public:
  explicit IntValue(int value) : value_(value) {
  }

  void to_string(std::ostream &os) const override {
    os << value_;
  }

  int compare(const TupleValue &other) const override {
    const IntValue & int_other = (const IntValue &)other;
    return value_ - int_other.value_;
  }

  void* value() const override {
    return (void*)&value_;
  }

  TupleValue* get_pointer() override {
    return this;
  }

const std::shared_ptr<TupleValue> compute(int agg_type, const std::shared_ptr<TupleValue> other) override;

private:
  int value_;
};

class FloatValue : public TupleValue {
public:
  explicit FloatValue(float value) : value_(value) {
  }

  void to_string(std::ostream &os) const override {
    os << value_;
  }

  int compare(const TupleValue &other) const override {
    const FloatValue & float_other = (const FloatValue &)other;
    float result = value_ - float_other.value_;
    if (result > 0) { // 浮点数没有考虑精度问题
      return 1;
    }
    if (result < 0) {
      return -1;
    }
    return 0;
  }

  void* value() const override {
    return (void*)&value_;
  }

  TupleValue* get_pointer() override {
    return this;
  }
  const std::shared_ptr<TupleValue> compute(int agg_type, const std::shared_ptr<TupleValue> other) override;

private:
  float value_;
};

class StringValue : public TupleValue {
public:
  StringValue(const char *value, int len) : value_(value, len){
  }
  explicit StringValue(const char *value) : value_(value) {
  }

  void to_string(std::ostream &os) const override {
    os << value_;
  }

  int compare(const TupleValue &other) const override {
    const StringValue &string_other = (const StringValue &)other;
    return strcmp(value_.c_str(), string_other.value_.c_str());
  }

  void* value() const override {
    return (void*)value_.data();
  }

  TupleValue* get_pointer() override {
    return this;
  }
const std::shared_ptr<TupleValue> compute(int agg_type, const std::shared_ptr<TupleValue> other) override;

private:
  std::string value_;
  std::shared_ptr<TupleValue> ptr_;
};

std::shared_ptr<TupleValue> get_tuple_value(void* data, AttrType attr_type);


#endif //__OBSERVER_SQL_EXECUTOR_VALUE_H_
