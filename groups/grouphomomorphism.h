#pragma once

#include <map>

#include "../monoids/monoidhomomorphism.h"
#include "group.h"


template <class T, class S>
class GroupHomomorphism : public MonoidHomomorphism<T, S> {
  public:
    GroupHomomorphism(Group<T> dom_group,
                      Group<S> codom_group,
                      std::map<T, S> eval);
    Group<T> domain();
    Group<S> codomain();
  private:
    Group<T> domain_;
    Group<S> codomain_;
};

template <class T, class S>
GroupHomomorphism<T, S>::GroupHomomorphism(Group<T> dom_group,
                                           Group<S> codom_group,
                                           std::map<T, S> eval)
                        : MonoidHomomorphism<T, S>(dom_group, 
                                             codom_group,
                                             eval),
                          domain_(dom_group), 
                          codomain_(codom_group) {

}        

template <class T, class S>
Group<T> GroupHomomorphism<T, S>::domain() {
  return domain_;
}                

template <class T, class S>
Group<S> GroupHomomorphism<T, S>::codomain() {
  return codomain_;
}   
