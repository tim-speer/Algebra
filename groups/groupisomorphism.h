#pragma once

#include "grouphomomorphism.h"

template <class T, class S>
void check_valid_isomorphism(GroupHomomorphism<T, S> homomorphism) {
  if (!homomorphism.bijective())
    throw std::invalid_argument("A group isomorphism needs to be bijective");
}

template <class T, class S>
class GroupIsomorphism : public GroupHomomorphism<T, S> {
  public:
    GroupIsomorphism(GroupHomomorphism<T, S> homomorphism);
};

template <class T, class S>
GroupIsomorphism<T, S>::GroupIsomorphism(GroupHomomorphism<T, S>
                                         homomorphism) 
                       : GroupHomomorphism<T, S>(homomorphism) {
  check_valid_isomorphism(homomorphism);
}
