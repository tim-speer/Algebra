#pragma once

#include "group.h"

template <class T>
class AbelianGroup : public Group<T> {
  public:
    AbelianGroup(Group<T> group);
};

template <class T>
AbelianGroup<T>::AbelianGroup(Group<T> group) 
                             : Group<T>(group) {
  check_abelian(group);
}

template <class T>
void check_abelian(Group<T> group) {
  for (T a : group.elements()) {
    for (T b : group.elements()) {
      if (group.op().apply(a, b) != group.op().apply(b, a))
        throw std::invalid_argument("group is not abelian");
    }
  }
}
