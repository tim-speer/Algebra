#pragma once

#include <functional>
#include <set>

#include "../functions/function.h"
#include "monoid.h"

template <class T, class S>
void check_valid_monoid_homomorphism(Monoid<T> dom_monoid,
                                     Monoid<S> codom_monoid,
                                     std::function<S(T)> func) {
  if (!(func(dom_monoid.identity()) == codom_monoid.identity()))
    throw std::invalid_argument("monoid homomorphism needs to map "
                                "identity to identity");

  for (std::pair<T, T> element : dom_monoid.op().domain()) {
    S left = codom_monoid.op().apply(func(element.first), 
                                     func(element.second));
    S right = func(dom_monoid.op().apply(element.first,
                                         element.second));
    std::cout << left << " = " << right << std::endl;
    if (!(left == right))
      throw std::invalid_argument("multiplicative property of monoid "
                                  "homomorphism is not satisfied");
  }
}

template <class T, class S>
class MonoidHomomorphism : Function<T, S> {
  public:
    MonoidHomomorphism(Monoid<T> dom_monoid, 
                       Monoid<S> codom_monoid,
                       std::function<S(T)> func);
};

template <class T, class S>
MonoidHomomorphism<T, S>::MonoidHomomorphism(Monoid<T> dom_monoid,
                                             Monoid<S> codom_monoid,
                                             std::function<S(T)> func)
                          : Function<T, S>(dom_monoid.elements(),
                                           codom_monoid.elements(),
                                           func) {
  check_valid_monoid_homomorphism(dom_monoid,
                                  codom_monoid,
                                  func);
}
