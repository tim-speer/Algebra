#pragma once

#include "monoidmod.h"

class MultiplyModMonoid : public MonoidMod {
  public:
    MultiplyModMonoid(int n);
};

MultiplyModMonoid::MultiplyModMonoid(int n) : MonoidMod(OpMod(n, '*')) {

}
