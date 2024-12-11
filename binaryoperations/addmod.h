#pragma once

#include "opmod.h"

class AddMod : public OpMod {
  public: 
    AddMod(int n);
};

AddMod::AddMod(int n) : OpMod(n, '+') {

};
