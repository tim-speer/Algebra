#pragma once

#include <map>
#include <set>

template <class T, class S>
void check_valid_function(std::set<T> domain,
                          std::set<S> codomain,
                          std::map<T, S> eval) {
  for (T element : domain) {
    if (!codomain.contains(eval[element]))
      throw std::invalid_argument("eval is not valid from domain"
                                  " to codomain");
  }
}

template <class T, class S>
class Function {
  public:
    Function(std::set<T> domain, 
             std::set<S> codomain, 
             std::map<T, S> eval);
    bool injective();
    bool surjective();
    bool bijective();
    std::set<T> domain();
    std::set<S> codomain();
    std::map<T, S> eval();
  private:
    std::set<T> domain_;
    std::set<S> codomain_;
    std::map<T, S> eval_;
};

template <class T, class S>
Function<T, S>::Function(std::set<T> domain, 
                         std::set<S> codomain,
                         std::map<T, S> eval) {

  check_valid_function(domain, codomain, eval);
  domain_ = domain;
  codomain_ = codomain;
  eval_ = eval;
}

template <class T, class S>
bool Function<T, S>::injective() {
  for (T x : domain_) {
    for (T y : domain_) {
      if (x != y && eval_[x] == eval_[y])
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
      if (eval_[x] == y) {
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
std::map<T, S> Function<T, S>::eval() {
  return eval_;
}
