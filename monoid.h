#pragma once

#include <set>
#include "binaryoperation.h"

template <class T>
class Monoid {
  public:
    Monoid(std::set<T> elements, BinaryOperation<T> op);
  private:
    std::set<T> elements_;
    BinaryOperation<T> op_;
};

template <class T>
Monoid<T>::Monoid(std::set<T> elements, BinaryOperation<T> op)
                  : elements_(elements), op_(op) {
  check_valid_monoid(elements, op);
}

template <class T>
void check_valid_monoid(std::set<T> elements, BinaryOperation<T> op) {
  check_empty(elements);
  if (elements != op.codomain())
    throw std::invalid_argument("op must be a binary"
                                "operation on elements");
}
