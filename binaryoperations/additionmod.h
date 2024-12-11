#pragma once

#include <set>
#include <functional>
#include <stdexcept>

#include "binaryoperation.h"

class AdditionMod : public BinaryOperation<int> {
  public:
    AdditionMod(int n);
  private:
    int modulus_;
};

std::set<int> make_elements(int n) {
  std::set<int> elements = std::set<int>();
  for (int i = 0; i < n; i++)
    elements.insert(i);

  return elements;
}

std::function<int(int, int)> add(int n) {
  return [n](int a, int b) { return (a + b) % n;}; 
}

void check_modulus(int n) {
  if (n < 2)
    throw std::invalid_argument("n must be >= to 2");
} 

AdditionMod::AdditionMod(int n) : BinaryOperation<int>(make_elements(n), 
                                                       add(n)) {
  check_modulus(n);
  modulus_ = n;
}
