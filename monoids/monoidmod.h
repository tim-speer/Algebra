#pragma once

#include "../binaryoperations/opmod.h"
#include "monoid.h"

class MonoidMod : public Monoid<int> {
  public:
    MonoidMod(OpMod op);
    OpMod op();
    void display();
  private:
    OpMod op_;
};

MonoidMod::MonoidMod(OpMod op) : Monoid<int>(op.codomain(), op), 
                                 op_(op) {

}

OpMod MonoidMod::op() {
  return op_;
}

void MonoidMod::display() {
  op_.display();
  std::cout << "Identity: " << identity() << std::endl;
}
