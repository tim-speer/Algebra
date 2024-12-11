#include <iostream>
#include <set>
#include <stdexcept>
#include <functional>
#include <utility>

#include "opmod.h"

std::set<int> make_elements(int n) {
  std::set<int> elements = std::set<int>();
  for (int i = 0; i < n; i++)
    elements.insert(i);

  return elements;
}

std::function<int(int, int)> op_func(int n, char op_type) {
  if (op_type == '+')
    return [n](int a, int b) { return (a + b) % n;};
  else if (op_type == '*')
    return [n](int a, int b) { return (a * b) % n;};
  throw std::invalid_argument("op_type should be + or *");
}

void check_modulus(int n) {
  if (n < 2)
    throw std::invalid_argument("n must be >= to 2");
}

OpMod::OpMod(int n, char op_type) 
            : BinaryOperation<int>(make_elements(n),
                                   op_func(n, op_type)) {
  check_modulus(n);
  modulus_ = n;
  op_type_ = op_type;
}

void OpMod::display() {
  std::cout << "Modulus: " << modulus_ << std::endl;
  std::cout << "Op Type: " << op_type_ << std::endl;

  for (std::pair<int, int> element : domain())
    std::cout << element.first << " " << op_type_ << " " 
              << element.second << " = " 
              << apply(element.first, element.second)
              << std::endl; 
}

int OpMod::modulus() {
  return modulus_;
}

char OpMod::op_type() {
  return op_type_;
}
