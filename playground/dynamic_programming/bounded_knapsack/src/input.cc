#include "../include/input.hh"

#include <fstream>
#include <iostream>

const std::string Input::ITEM_NAMES_PATH = "../assets/item_names.data";

const Input::MinMax Input::GENERATED_ITEMS_RANGE = std::make_pair(1, 305);
const Input::MinMax Input::KNAPSACK_CAPACITY_RANGE = std::make_pair(1, 5000);
const Input::MinMax Input::ITEM_COST_RANGE = std::make_pair(1, 1000);
const Input::MinMax Input::ITEM_QUANTITY_RANGE = std::make_pair(1, 100);
const Input::MinMax Input::ITEM_WEIGHT_RANGE = std::make_pair(1, 500);

void Input::read_item_names() {
  std::ifstream file(ITEM_NAMES_PATH);
  if (!file.is_open()) {
    std::cout << "Failed to open a file with item names at given path: "
              << ITEM_NAMES_PATH << '\n';
    return;
  }
  std::string line;
  while (std::getline(file, line)) {
    item_names.push_back(line);
  }
  file.close();
}

Knapsack Input::generate_knapsack() {
  knapsack.capacity = random(KNAPSACK_CAPACITY_RANGE);
  return knapsack;
}

std::vector<Item> Input::generate_items() {
  read_item_names();

  int size = random(GENERATED_ITEMS_RANGE);
  std::vector<Item> items(size);

  for (auto& it : items) {
    it.cost = random(ITEM_COST_RANGE);
    it.weight = random(ITEM_WEIGHT_RANGE);
    it.quantity = random(ITEM_QUANTITY_RANGE);
  }

  return items;
}

void Input::print_knapsack() {
  std::cout << "Knapsack:\n";
  std::cout << " capacity <= " << knapsack.capacity << "\n";
}

void Input::print_generated_items() {
  std::cout << "Generated items:\n";
  for (auto& item : items) item.print();
}