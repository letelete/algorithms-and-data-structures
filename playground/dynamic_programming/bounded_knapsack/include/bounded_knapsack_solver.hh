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

class BoundedKnapsackSolver {
 private:
  int maximal_profit;
  std::vector<Item> most_profitable_items;

  Knapsack knapsack;
  std::vector<Item> items;

 public:
  BoundedKnapsackSolver(Knapsack knapsack_, std::vector<Item> items_)
      : knapsack(knapsack_), items(items_) {
    this->maximal_profit = 0;
    this->most_profitable_items.clear();
  };

  void print_maximal_profit();

  void print_most_profitable_items();

  void solve();
};