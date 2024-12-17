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
    if (!(left == right))
      throw std::invalid_argument("multiplicative property of monoid "
                                  "homomorphism is not satisfied");
  }
}

template <class T, class S>
class MonoidHomomorphism : public Function<T, S> {
  public:
    MonoidHomomorphism(Monoid<T> dom_monoid, 
                       Monoid<S> codom_monoid,
                       std::function<S(T)> func);
    Monoid<T> domain();
    Monoid<S> codomain();
  private:
    Monoid<T> domain_;
    Monoid<S> codomain_;
};

template <class T, class S>
MonoidHomomorphism<T, S>::MonoidHomomorphism(Monoid<T> dom_monoid,
                                             Monoid<S> codom_monoid,
                                             std::function<S(T)> func)
                          : Function<T, S>(dom_monoid.elements(),
                                           codom_monoid.elements(),
                                           func), 
                            domain_(dom_monoid), 
                            codomain_(codom_monoid) {
  check_valid_monoid_homomorphism(dom_monoid,
                                  codom_monoid,
                                  func);
}

template <class T, class S>
Monoid<T> MonoidHomomorphism<T, S>::domain() {
  return domain_;
}

template <class T, class S>
Monoid<S> MonoidHomomorphism<T, S>::codomain() {
  return codomain_;
}
