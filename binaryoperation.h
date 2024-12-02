#pragma once

#include <set>
#include <functional>

#include "productset.h"
#include "checks.h"

template <class T>
class BinaryOperation {
  public:
    BinaryOperation(std::set<T> elements, 
                    std::function<T(T, T)> op);
    ProductSet<T> domain();
    std::set<T> codomain();
    T apply(T x, T y);
  private:
    ProductSet<T> domain_;
    std::set<T> codomain_;
    std::function<T(T, T)> op_;
};

template <class T>
BinaryOperation<T>::BinaryOperation(std::set<T> elements,
                                    std::function<T(T, T)> op)
                                    : domain_(elements), 
                                      codomain_(elements),    
                                      op_(op) {
  checks::check_valid_bin_op(domain_, codomain_, op_);
}

template <class T> 
ProductSet<T> BinaryOperation<T>::domain() {
  return domain_;
}

template <class T>
std::set<T> BinaryOperation<T>::codomain() {
  return codomain_;
}

template <class T>
T BinaryOperation<T>::apply(T x, T y) {
  return op_(x, y);
}
