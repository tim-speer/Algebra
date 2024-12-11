#pragma once

#include <set>
#include <functional>
#include <string>

#include "../productset.h"

template <class T>
class BinaryOperation {
  public:
    BinaryOperation(std::set<T> elements, 
                    std::function<T(T, T)> op);
    ProductSet<T> domain();
    std::set<T> codomain();
    std::function<T(T, T)> func();
    T apply(T x, T y);
    bool operator==(const BinaryOperation<T> & bin_op) const;
  private:
    ProductSet<T> domain_;
    std::set<T> codomain_;
    std::function<T(T, T)> func_;
};

template <class T>
BinaryOperation<T>::BinaryOperation(std::set<T> elements,
                                    std::function<T(T, T)> op)
                                    : domain_(elements), 
                                      codomain_(elements),    
                                      func_(op) {
  check_valid_bin_op(domain_, codomain_, func_);
}

template <class T>
bool BinaryOperation<T>::operator==(const BinaryOperation<T> & bin_op) const {
  if (codomain_ == bin_op.codomain_) {
    for (auto element : domain_) {
      if (func_(element.first, element.second) != 
          bin_op.func_(element.first, element.second))
        return false;
    }

    return true;

  }

  return false;

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
std::function<T(T, T)> BinaryOperation<T>::func() {
  return func_;
}

template <class T>
T BinaryOperation<T>::apply(T x, T y) {
  return func_(x, y);
}

template <class T>
void check_valid_bin_op(ProductSet<T> domain, 
                        std::set<T> codomain, 
                        std::function<T(T, T)> op) {
  check_empty(codomain);            
  check_op_closed(domain, codomain, op);
}

template <class T>
void check_op_closed(ProductSet<T> domain,
                     std::set<T> codomain,  
                     std::function<T(T, T)> op) {
  for (auto element : domain)
    if (!codomain.contains(op(element.first, element.second)))
      throw std::invalid_argument("op is not closed");
} 
