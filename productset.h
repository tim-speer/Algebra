#pragma once

#include <set>
#include <utility>

template <class T>
class ProductSet : public std::set<std::pair<T, T>> {
  public:
    ProductSet(std::set<T> elements);    
};

template <class T>
ProductSet<T>::ProductSet(std::set<T> elements) {
  for (T left : elements) {
    for (T right : elements) {
      this->insert(std::pair<T, T>(left, right));  
    }
  }  
}
