#pragma once

#include <vector>

#include "item.hh"

class PrettyPrinter {
 private:
  static const char border_char = '*';
  static const int item_margin = 2;

  int fixed_column_width(const std::vector<Item>& items);

 public:
  void printItemsHorizontally(const std::vector<Item>& items);
};