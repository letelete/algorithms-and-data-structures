#include "../include/input.hh"

#include <algorithm>
#include <fstream>
#include <iostream>

const std::string Input::_ITEM_NAMES_PATH = "../assets/item_names.data";

const Input::MinMax Input::_GENERATED_ITEMS_RANGE = std::make_pair(2, 3);
const Input::MinMax Input::_KNAPSACK_CAPACITY_RANGE = std::make_pair(1, 20);
const Input::MinMax Input::_ITEM_COST_RANGE = std::make_pair(1, 20);
const Input::MinMax Input::_ITEM_QUANTITY_RANGE = std::make_pair(1, 3);
const Input::MinMax Input::_ITEM_WEIGHT_RANGE = std::make_pair(1, 20);

Knapsack* Input::generate_knapsack() {
  _knapsack->capacity = _random(_KNAPSACK_CAPACITY_RANGE);
  return _knapsack;
}

std::vector<Item*> Input::generate_items() {
  _read_item_names();

  int size = _random(_GENERATED_ITEMS_RANGE);
  _items = std::vector<Item*>(size);

  for (auto& it : _items) {
    it = new Item;

    auto name_range = Input::MinMax{0, _item_names.size() - 1};
    int name_index = _random(name_range);

    it->cost = _random(_ITEM_COST_RANGE);
    it->weight = _random(_ITEM_QUANTITY_RANGE);
    it->quantity = _random(_ITEM_QUANTITY_RANGE);
    it->name = _item_names[name_index];
  }

  std::sort(_items.begin(), _items.end());

  return _items;
}

void Input::_read_item_names() {
  std::ifstream file(_ITEM_NAMES_PATH);
  if (!file.is_open()) {
    std::cout << "Failed to open a file with item names at given path: "
              << _ITEM_NAMES_PATH << '\n';
    return;
  }
  std::string line;
  while (std::getline(file, line)) {
    _item_names.push_back(line);
  }
  file.close();
}