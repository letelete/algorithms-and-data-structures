#pragma once

#include <vector>

#include "item.hh"
#include "knapsack.hh"

class PrettyPrinter {
 public:
  void print_items_horizontally(const std::vector<Item*>& items);

 private:
  static const char _border_indicator = '*';
  static const int _item_horizontal_margin = 2;

  int _fixed_column_width(const std::vector<Item*>& items);
};