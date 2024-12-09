#pragma once

#include <map>
#include "monoid.h"

template <class T>
class Group : public Monoid<T> {
  public:
    Group(Monoid<T> monoid);
    std::map<T, T> inverses();
    T inverse(T element);
  private:
    std::map<T, T> inverses_;
};

template <class T>
Group<T>::Group(Monoid<T> monoid) : Monoid<T>(monoid.elements(), 
                                              monoid.op()) {
  inverses_ = check_valid_group(monoid);
}

template <class T>
std::map<T, T> Group<T>::inverses() {
  return inverses_;
}

template <class T>
T Group<T>::inverse(T element) {
  return inverses_[element];
}

template <class T>
std::map<T, T> check_valid_group(Monoid<T> monoid) {
  std::map<T, T> inverses = std::map<T, T>();
  for (T element : monoid.elements()) {
    T inverse = check_inverse(element, monoid);
    inverses[element] = inverse;
  }

  return inverses;  
}

template <class T>
T check_inverse(T element, Monoid<T> monoid) {
  for (T pot_inv : monoid.elements()) {
    if (monoid.op().apply(pot_inv, element) == monoid.identity() &&
        monoid.op().apply(element, pot_inv) == monoid.identity()) {
      return pot_inv;
    }
  }  

  throw std::invalid_argument("element does not have an inverse");

}
