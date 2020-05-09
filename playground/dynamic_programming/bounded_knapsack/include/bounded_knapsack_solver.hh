#pragma once

/**
 * The Bounded Knapsack Problem:
 * Maximize the profit of possible items combination which you can fit into your
 * knapsack assuming:
 * - you cannot exceed a weight of the knapsack
 * - you cannot split items; you can either take the item, or leave it
 * - each item is disposable in the limited amount
 */

#include <vector>

#include "item.hh"
#include "knapsack.hh"
#include "pretty_printer.hh"

class BoundedKnapsackSolver {
 private:
  int maximal_items_value;
  int maximal_profit;
  std::vector<Item> most_profitable_items;

  PrettyPrinter* printer;
  Knapsack knapsack;
  std::vector<Item> items;

  int calculate_maximal_items_value();

 public:
  BoundedKnapsackSolver(Knapsack knapsack_, std::vector<Item> items_)
      : knapsack(knapsack_), items(items_) {
    this->maximal_profit = 0;
    this->maximal_items_value = -1;
    most_profitable_items.clear();
  };

  ~BoundedKnapsackSolver() { delete printer; };

  void print_maximal_profit();

  void print_most_profitable_items();

  void solve();
};