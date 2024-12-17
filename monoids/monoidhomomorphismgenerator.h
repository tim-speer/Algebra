#pragma once

#include <vector>
#include "../functions/functiongenerator.h"

template <class T, class S>
class MonoidHomomorphismGenerator { 
  public:
    MonoidHomomorphismGenerator(Monoid<T> dom_monoid,
                                Monoid<S> codom_monoid);
    std::vector<MonoidHomomorphism<T, S>> homomorphisms();
  private:
    std::vector<MonoidHomomorphism<T, S>> homomorphisms_;
};

template <class T, class S>
MonoidHomomorphismGenerator<T, S>::MonoidHomomorphismGenerator(
                                   Monoid<T> dom_monoid,
                                   Monoid<S> codom_monoid) {
  
  auto function_gen = FunctionGenerator<T, S>(dom_monoid.elements(),
                                              codom_monoid.elements());
  
  for (auto function : function_gen.functions()) {
    try {
      MonoidHomomorphism<T, S> hom{dom_monoid, codom_monoid, function.eval()}; 
      homomorphisms_.push_back(hom);
    } catch(std::invalid_argument) {

    }
  }
}

template <class T, class S>
std::vector<MonoidHomomorphism<T, S>> MonoidHomomorphismGenerator<T, S>::homomorphisms() {
  return homomorphisms_;
}
