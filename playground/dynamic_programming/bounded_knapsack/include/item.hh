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
    return name <= item.name && cost <= item.cost && weight <= item.weight;
  }

  const std::string name_tag() { return name; }

  const std::string cost_tag() {
    auto cost_string = std::to_string(cost);
    return cost_string + " $";
  }

  const std::string weight_tag() {
    auto weight_string = std::to_string(weight);
    return weight_string + " kg";
  }

  const std::string quantity_tag() {
    auto quantity_string = std::to_string(quantity);
    return "x" + quantity_string;
  }
};