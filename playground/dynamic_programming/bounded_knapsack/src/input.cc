#include "../include/input.hh"

#include <fstream>
#include <iostream>

const std::string Input::ITEM_NAMES_PATH = "../assets/item_names.data";

const Input::MinMax Input::GENERATED_ITEMS_RANGE = std::make_pair(2, 10);
const Input::MinMax Input::KNAPSACK_CAPACITY_RANGE = std::make_pair(1, 100);
const Input::MinMax Input::ITEM_COST_RANGE = std::make_pair(1, 20);
const Input::MinMax Input::ITEM_QUANTITY_RANGE = std::make_pair(1, 3);
const Input::MinMax Input::ITEM_WEIGHT_RANGE = std::make_pair(1, 10);

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
  items = std::vector<Item>(size);

  for (auto& it : items) {
    auto name_range = Input::MinMax{0, item_names.size() - 1};
    int name_index = random(name_range);

    it.cost = random(ITEM_COST_RANGE);
    it.weight = random(ITEM_WEIGHT_RANGE);
    it.quantity = random(ITEM_QUANTITY_RANGE);
    it.name = item_names[name_index];
  }

  return items;
}

void Input::print_knapsack() {
  std::cout << "You have " << knapsack.capacity
            << " kg of capacity in your knapsack\n";
}

void Input::print_generated_items() {
  std::cout << "You have " << items.size() << " different items available:\n";
  printer->printItemsHorizontally(items);
}