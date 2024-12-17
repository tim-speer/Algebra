#pragma once

#include <vector>

#include "monoidisomorphism.h"
#include "monoidhomomorphismgenerator.h"

template <class T, class S>
class MonoidIsomorphismGenerator {
  public:
    MonoidIsomorphismGenerator(Monoid<T> dom_monoid,
                               Monoid<S> codom_monoid);
    std::vector<MonoidIsomorphism<T, S>> isomorphisms();
  private:
    std::vector<MonoidIsomorphism<T, S>> isomorphisms_;
};

template <class T, class S>
MonoidIsomorphismGenerator<T, S>::MonoidIsomorphismGenerator(
                                  Monoid<T> dom_monoid,
                                  Monoid<S> codom_monoid) {

  auto hom_gen = MonoidHomomorphismGenerator<T, S>(dom_monoid,
                                                   codom_monoid);

  for (auto hom : hom_gen.homomorphisms()) {
    try {
      MonoidIsomorphism<T, S> iso{hom};
      isomorphisms_.push_back(iso);
    } catch(std::invalid_argument) {

    }
  }
}

template <class T, class S>
std::vector<MonoidIsomorphism<T, S>> MonoidIsomorphismGenerator<T, S>::isomorphisms() {
  return isomorphisms_;
}
