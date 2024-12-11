#pragma once

#include "opmod.h"

class MultiplyMod : public OpMod {
  public: 
    MultiplyMod(int n);
};

MultiplyMod::MultiplyMod(int n) : OpMod(n, '*') {

};
