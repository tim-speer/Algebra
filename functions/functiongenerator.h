#pragma once

#include <set>
#include <vector>
#include <map>

#include "function.h"
#include "../cartesianproduct.h"

template <class T, class S>
class FunctionGenerator {
  public:
    FunctionGenerator(std::set<T> domain, std::set<S> codomain);
    std::vector<Function<T, S>> functions();
  private:
    std::vector<Function<T, S>> functions_;
};

template <class T, class S>
FunctionGenerator<T, S>::FunctionGenerator(std::set<T> domain,
                                           std::set<S> codomain) {
  auto functions_data = CartesianProduct<S>(codomain, domain.size());  
  for (auto data : functions_data) {
    int i = 0;
    std::map<T, S> eval;
    for (T x : domain) {
      eval[x] = data[i];
      i++;  
    }
    functions_.push_back(Function<T, S>(domain, codomain, eval));
  }
}

template <class T, class S>
std::vector<Function<T, S>> FunctionGenerator<T, S>::functions() {
  return functions_;
}
