#pragma once

#include "../monoids/addmodmonoid.h"
#include "group.h"

class AddModGroup : public Group<int> {
  public:
    AddModGroup(int n);
};

AddModGroup::AddModGroup(int n) : Group<int>(AddModMonoid(n)) {
}
