#pragma once

#include <chrono>
#include <random>
#include <string>
#include <vector>

#include "item.hh"
#include "knapsack.hh"
#include "pretty_printer.hh"

class Input {
 private:
  typedef std::pair<int, int> MinMax;
  using Time = std::chrono::high_resolution_clock;

  static const MinMax GENERATED_ITEMS_RANGE;
  static const MinMax KNAPSACK_CAPACITY_RANGE;
  static const MinMax ITEM_COST_RANGE;
  static const MinMax ITEM_QUANTITY_RANGE;
  static const MinMax ITEM_WEIGHT_RANGE;

  static const std::string ITEM_NAMES_PATH;

  unsigned seed = static_cast<unsigned>(Time::now().time_since_epoch().count());
  std::mt19937 gen = std::mt19937(seed);

  int random(MinMax range) {
    return std::uniform_int_distribution<int>{range.first, range.second}(gen);
  }

  std::vector<std::string> item_names;
  std::vector<Item> items;
  Knapsack knapsack;

  PrettyPrinter* printer;

  void read_item_names();

 public:
  Input() : printer(new PrettyPrinter){};

  ~Input() { delete printer; }

  Knapsack generate_knapsack();

  std::vector<Item> generate_items();

  void print_knapsack();

  void print_generated_items();
};