#pragma once

#include "monoidhomomorphism.h"

template <class T, class S>
void check_valid_isomorphism(MonoidHomomorphism<T, S> homomorphism) {
  if (!homomorphism.bijective())
    throw std::invalid_argument("A monoid isomorphism needs to be bijective");
}

template <class T, class S>
class MonoidIsomorphism : public MonoidHomomorphism<T, S> {
  public:
    MonoidIsomorphism(MonoidHomomorphism<T, S> homomorphism);
};

template <class T, class S>
MonoidIsomorphism<T, S>::MonoidIsomorphism(MonoidHomomorphism<T, S>
                                           homomorphism) 
                         : MonoidHomomorphism<T, S>(homomorphism) {
  check_valid_isomorphism(homomorphism);
}
