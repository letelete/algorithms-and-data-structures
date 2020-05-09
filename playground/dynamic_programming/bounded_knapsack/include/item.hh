#pragma once

#include <iostream>
#include <string>

struct Item {
  std::string name;
  int cost;
  int weight;
  int quantity;
  void print() {
    std::cout << quantity << " x " << name << "\n";
    std::cout << cost << " $\n";
    std::cout << weight << " kg\n";
    std::cout << "--\n";
  }
};