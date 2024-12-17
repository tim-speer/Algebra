#pragma once

#include <functional>
#include <set>

template <class T, class S>
void check_valid_function(std::set<T> domain,
                          std::set<S> codomain,
                          std::function<S(T)> func) {
  for (T element : domain) {
    if (!codomain.contains(func(element)))
      throw std::invalid_argument("func is not valid from domain"
                                  " to codomain");
  }
}

template <class T, class S>
class Function {
  public:
    Function(std::set<T> domain, 
             std::set<S> codomain, 
             std::function<S(T)>);
    bool injective();
    bool surjective();
    bool bijective();
    std::set<T> domain();
    std::set<S> codomain();
    std::function<S(T)> func();
  private:
    std::set<T> domain_;
    std::set<S> codomain_;
    std::function<S(T)> func_;
};

template <class T, class S>
Function<T, S>::Function(std::set<T> domain, 
                         std::set<S> codomain,
                         std::function<S(T)> func) {

  check_valid_function(domain, codomain, func);
  domain_ = domain;
  codomain_ = codomain;
  func_ = func;
}

template <class T, class S>
bool Function<T, S>::injective() {
  for (T x : domain_) {
    for (T y : domain_) {
      if (x != y && func_(x) == func_(y))
        return false;
    }
  }

  return true;

}

template <class T, class S>
bool Function<T, S>::surjective() {
  for (S y : codomain_) {
    bool found_preimage = false;
    for (T x : domain_) {
      if (func_(x) == y) {
        found_preimage = true;
        break;
      }
    }

    if (!found_preimage)
      return false;
  }

  return true;  

}

template <class T, class S>
bool Function<T, S>::bijective() {
  if (injective() && surjective())
    return true;

  return false;
}

template <class T, class S>
std::set<T> Function<T, S>::domain() {
  return domain_;
}

template <class T, class S>
std::set<S> Function<T, S>::codomain() {
  return codomain_;
}

template <class T, class S>
std::function<S(T)> Function<T, S>::func() {
  return func_;
}
