#include <set>
#include <stdexcept>

template <class T>
class BinaryOperation {
  public:
    BinaryOperation(std::set<T> elements);
    std::set<T> get_elements();
  private:
    std::set<T> elements_;
};

template <class T>
BinaryOperation<T>::BinaryOperation(std::set<T> elements) {
  if (elements.empty())
    throw std::invalid_argument("elements should not be empty");  

  elements_ = elements;
}

template <class T> 
std::set<T> BinaryOperation<T>::get_elements() {
  return elements_;
} 
