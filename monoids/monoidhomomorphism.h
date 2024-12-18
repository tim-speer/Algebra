#pragma once

#include <map>
#include <set>

#include "../functions/function.h"
#include "monoid.h"

template <class T, class S>
void check_valid_monoid_homomorphism(Monoid<T> dom_monoid,
                                     Monoid<S> codom_monoid,
                                     std::map<T, S> eval) {
  if (!(eval[dom_monoid.identity()] == codom_monoid.identity()))
    throw std::invalid_argument("monoid homomorphism needs to map "
                                "identity to identity");

  for (std::pair<T, T> element : dom_monoid.op().domain()) {
    S left = codom_monoid.op().apply(eval[element.first], 
                                     eval[element.second]);
    S right = eval[dom_monoid.op().apply(element.first,
                                         element.second)];
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
                       std::map<T, S> eval);
    Monoid<T> domain();
    Monoid<S> codomain();
  private:
    Monoid<T> domain_;
    Monoid<S> codomain_;
};

template <class T, class S>
MonoidHomomorphism<T, S>::MonoidHomomorphism(Monoid<T> dom_monoid,
                                             Monoid<S> codom_monoid,
                                             std::map<T, S> eval)
                          : Function<T, S>(dom_monoid.elements(),
                                           codom_monoid.elements(),
                                           eval), 
                            domain_(dom_monoid), 
                            codomain_(codom_monoid) {
  check_valid_monoid_homomorphism(dom_monoid,
                                  codom_monoid,
                                  eval);
}

template <class T, class S>
Monoid<T> MonoidHomomorphism<T, S>::domain() {
  return domain_;
}

template <class T, class S>
Monoid<S> MonoidHomomorphism<T, S>::codomain() {
  return codomain_;
}
