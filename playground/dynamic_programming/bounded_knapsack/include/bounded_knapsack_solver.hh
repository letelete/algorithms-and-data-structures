#pragma once

/**
 * The Bounded Knapsack Problem:
 * Maximize the profit of possible items combination which you can fit into your
 * knapsack assuming:
 * - you cannot exceed a weight of the knapsack
 * - you cannot split items; you can either take the item, or leave it
 * - each item is disposable in the limited amount
 */

#include <numeric>
#include <stack>
#include <unordered_map>
#include <vector>

#include "item.hh"
#include "knapsack.hh"
#include "pretty_printer.hh"

class BoundedKnapsackSolver {
 public:
  typedef std::vector<Item*> Items;

  BoundedKnapsackSolver(Knapsack* knapsack, Items items)
      : _knapsack(knapsack), _items(items) {
    this->_maximal_profit = 0;
    this->_maximal_items_value = -1;

    this->_solved = false;

    this->_most_profitable_items.clear();
    this->_price_relation.clear();
  };

  ~BoundedKnapsackSolver() {
    delete _printer;
    delete _knapsack;
    for (const auto& item : _items) delete item;
    for (const auto& item : _most_profitable_items) delete item;
  };

  int maximal_profit() {
    if (!_solved) _solve();
    return _maximal_profit;
  }

  Items most_profitable_items() {
    if (_most_profitable_items.empty()) _construct_most_profitable_items();
    return _most_profitable_items;
  }

  int maximal_items_value() {
    auto sum_item = [&](int sum, const Item* item) {
      return sum + (item->cost * item->quantity);
    };
    if (_maximal_items_value == -1) {
      _maximal_items_value =
          std::accumulate(_items.begin(), _items.end(), 0, sum_item);
    }
    return _maximal_items_value;
  }

 private:
  /**
   * We will mark an illegal cell with -1 value to identify that we cannot
   * build on top of it.
   */
  static const int _UNREACHABLE_PRICE = -1;

  int _maximal_items_value;
  int _maximal_profit;
  Items _most_profitable_items;
  bool _solved;

  /**
   * Provides access to reachable cells of certain price to calculate the best
   * weight for each.
   */
  std::vector<int> _weight_at_price;

  /**
   * Describes a relation of items saved as values needed to construct certain
   * price savd as a key.
   *
   * This structure lets access items relations in constant time.
   * Construction complexity is O(1).
   */
  std::unordered_map<int, std::stack<Item*>> _price_relation;

  PrettyPrinter* _printer;
  Knapsack* _knapsack;
  Items _items;

  void _construct_most_profitable_items();

  void _solve();

  void _update_weight_price(Item* item, int price);

  void _update_price_relation(Item* reached_with, int current_price,
                              int reachable_price);
};