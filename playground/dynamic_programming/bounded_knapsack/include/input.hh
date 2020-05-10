#pragma once

#include <chrono>
#include <random>
#include <string>
#include <vector>

#include "item.hh"
#include "knapsack.hh"

class Input {
 public:
  Input() : _knapsack(new Knapsack){};

  ~Input() {
    delete _knapsack;
    for (const auto& item : _items) delete item;
  }

  Knapsack* generate_knapsack();

  std::vector<Item*> generate_items();

 private:
  typedef std::pair<int, int> MinMax;
  using Time = std::chrono::high_resolution_clock;

  static const std::string _ITEM_NAMES_PATH;

  static const MinMax _GENERATED_ITEMS_RANGE;
  static const MinMax _KNAPSACK_CAPACITY_RANGE;
  static const MinMax _ITEM_COST_RANGE;
  static const MinMax _ITEM_QUANTITY_RANGE;
  static const MinMax _ITEM_WEIGHT_RANGE;

  unsigned _seed =
      static_cast<unsigned>(Time::now().time_since_epoch().count());
  std::mt19937 _gen = std::mt19937(_seed);

  int _random(MinMax range) {
    return std::uniform_int_distribution<int>{range.first, range.second}(_gen);
  }

  Knapsack* _knapsack;

  std::vector<Item*> _items;

  std::vector<std::string> _item_names;

  void _read_item_names();
};