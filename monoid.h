#pragma once

#include <set>
#include "binaryoperation.h"

template <class T>
class Monoid {
  public:
    Monoid(std::set<T> elements, BinaryOperation<T> op);
    std::set<T> elements();
    BinaryOperation<T> op();
    T identity();
  private:
    std::set<T> elements_;
    BinaryOperation<T> op_;
    T identity_;
};

template <class T>
Monoid<T>::Monoid(std::set<T> elements, BinaryOperation<T> op)
                  : elements_(elements), op_(op) {
  identity_ = check_valid_monoid(elements, op);
}

template <class T>
std::set<T> Monoid<T>::elements() {
  return elements_;
}

template <class T>
BinaryOperation<T> Monoid<T>::op() {
  return op_;
}

template <class T>
T Monoid<T>::identity() {
  return identity_;
}

template <class T>
T check_valid_monoid(std::set<T> elements, BinaryOperation<T> op) {
  check_empty(elements);
  if (elements != op.codomain())
    throw std::invalid_argument("op must be a binary"
                                "operation on elements");

  check_assoc(elements, op);
  T identity = check_identity(elements, op);
  return identity;
}

template <class T>
void check_assoc(std::set<T> elements, BinaryOperation<T> op) {
  for (T x : elements) {
    for (T y : elements) {
      for (T z : elements) {
        if (op.apply(x, op.apply(y, z)) != 
            op.apply(op.apply(x, y), z))  {
          throw std::invalid_argument("op is not associative");  
        }
      }
    }
  }
}

template <class T>
T check_identity(std::set<T> elements, BinaryOperation<T> op) {
  for (T pot_id : elements) {
    bool is_identity = true;
    for (T element : elements) {
      if (op.apply(pot_id, element) != element ||
          op.apply(element, pot_id) != element) {
        is_identity = false;
        break;
      }
    }

    if (is_identity)
      return pot_id;
  }

  throw std::invalid_argument("op does not have an identity");
}
