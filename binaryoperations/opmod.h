#pragma once

#include "binaryoperation.h"

class OpMod : public BinaryOperation<int> {
  public:
    OpMod(int n, char op_type);
    void display();
    int modulus();
    char op_type();
  private:
    int modulus_;
    char op_type_;
};
