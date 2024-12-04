#pragma once

#include <set>
#include <functional>
#include <string>

#include "productset.h"

template <class T>
class BinaryOperation {
  public:
    BinaryOperation(std::set<T> elements, 
                    std::function<T(T, T)> op);
    ProductSet<T> domain();
    std::set<T> codomain();
    T apply(T x, T y);
    bool has_identity();
  private:
    ProductSet<T> domain_;
    std::set<T> codomain_;
    std::function<T(T, T)> op_;
    std::string has_identity_;
};

template <class T>
BinaryOperation<T>::BinaryOperation(std::set<T> elements,
                                    std::function<T(T, T)> op)
                                    : domain_(elements), 
                                      codomain_(elements),    
                                      op_(op),
                                      has_identity_("unknown") {
  check_valid_bin_op(domain_, codomain_, op_);
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

template <class T>
bool BinaryOperation<T>::has_identity() {
  if (has_identity_ == "unknown") {
    for (T pot_id : codomain_) {
      bool is_identity = true;
      for (T element : codomain_) {
        if (apply(pot_id, element) != element ||
            apply(element, pot_id) != element) {
          is_identity = false;
          break;
        }
      }

      if (is_identity) {
        has_identity_ = "true";
        return true; 
      }
    }

    has_identity_ = "false";
   
  } else if (has_identity_ == "true") {
    return true;
  }
  return false;  
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
