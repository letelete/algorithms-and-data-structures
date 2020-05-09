#pragma once

#include <iostream>
#include <string>

struct Item {
  std::string name;
  int cost;
  int weight;
  int quantity;

  bool operator==(const Item& item) const {
    return name == item.name && cost == item.cost && weight == item.weight;
  }

  bool operator<(const Item& item) const {
    if (name == item.name) return cost > item.cost;
    return name > item.name;
  }
};