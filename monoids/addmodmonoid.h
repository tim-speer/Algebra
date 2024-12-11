#pragma once

#include "monoidmod.h"

class AddModMonoid : public MonoidMod {
  public:
    AddModMonoid(int n);
};

AddModMonoid::AddModMonoid(int n) : MonoidMod(OpMod(n, '+')) {

}
