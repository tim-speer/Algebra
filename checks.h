#pragma once

#include <stdexcept>

namespace checks {

  template <class T>
  void check_empty(std::set<T> elements) {
    if (elements.empty())
      throw std::invalid_argument("elements can't be empty");    
  }

  template <class T>
  void check_op_closed(ProductSet<T> domain,
                       std::set<T> codomain, 
                       std::function<T(T, T)> op) {
    for (auto element : domain)
      if (!codomain.contains(op(element.first, element.second)))
        throw std::invalid_argument("op is not closed"); 
  }

  template <class T>
  void check_valid_bin_op(ProductSet<T> domain, 
                          std::set<T> codomain, 
                          std::function<T(T, T)> op) {
    check_empty(codomain);
    check_op_closed(domain, codomain, op);
  }
}
