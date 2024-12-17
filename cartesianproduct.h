#pragma once

#include <set>
#include <vector>

#include "productset.h"

template <class T>
std::set<std::vector<T>> multiply(std::set<T> elements, unsigned factors) {
  std::set<std::vector<T>> prod;

  if (factors == 1) {
    for (T element : elements) {
      prod.insert(std::vector<T> {element});
    }
    return prod;
  }

  std::set<std::vector<T>> temp_prod = multiply(elements, factors - 1);
  for (std::vector<T> vec : temp_prod) {
    for (T element : elements) {
      std::vector<T> temp_vec = vec;
      temp_vec.push_back(element);
      prod.insert(temp_vec);
    }
  }

  return prod;
 
}

template <class T>
class CartesianProduct : public std::set<std::vector<T>> {
  public:
    CartesianProduct(std::set<T> elements, unsigned factors);
};

template <class T>
CartesianProduct<T>::CartesianProduct(std::set<T> elements,
                                      unsigned factors) 
                    : std::set<std::vector<T>>(multiply(elements, factors)) {

}
