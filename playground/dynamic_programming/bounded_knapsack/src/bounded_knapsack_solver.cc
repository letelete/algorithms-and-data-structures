#include "../include/bounded_knapsack_solver.hh"

#include <algorithm>

void BoundedKnapsackSolver::_construct_most_profitable_items() {
  if (!_solved) _solve();
  auto& relation = _price_relation[_maximal_profit];
  while (!relation.empty()) {
    _most_profitable_items.push_back(relation.top());
    relation.pop();
  }
  _price_relation.clear();
  std::sort(_most_profitable_items.begin(), _most_profitable_items.end());
}

void BoundedKnapsackSolver::_solve() {
  if (_items.empty()) return;
  if (_knapsack->capacity <= 0) return;

  /**
   * We will mark an illegal cell with -1 value to identify that we cannot
   * build on top of it.
   */
  const int ILLEGAL = -1;

  int extended_items_value = maximal_items_value() + 1;
  std::vector<int> weight_at_price(extended_items_value, ILLEGAL);

  // The base case is a state, where we didn't use any of _items, so all are
  // free
  weight_at_price[0] = 0;

  for (const auto& item : _items) {
    int copies_left = item->quantity;
    while (copies_left--) {
      for (int price = _maximal_profit; price >= 0; --price) {
        if (weight_at_price[price] == ILLEGAL) continue;

        int reachable_profit = price + item->cost;
        int alternative_weight = weight_at_price[price] + item->weight;
        int& reachable_profit_weight = weight_at_price[reachable_profit];

        bool weight_overload = alternative_weight > _knapsack->capacity;
        if (weight_overload) continue;

        bool dont_override_price =
            (reachable_profit_weight != ILLEGAL) &&
            (reachable_profit_weight <= alternative_weight);
        if (dont_override_price) continue;

        auto& reachable_relation = _price_relation[reachable_profit];

        Item* relative_item = item;
        relative_item->quantity = 1;

        if (reachable_profit == ILLEGAL) {
          reachable_relation.push(relative_item);
        } else {
          reachable_relation = _price_relation[price];
          if (!reachable_relation.empty()) {
            auto& item_at_top = reachable_relation.top();
            if (*item_at_top == *item) {
              item_at_top->quantity++;
            } else {
              reachable_relation.push(relative_item);
            }
          } else {
            reachable_relation.push(relative_item);
          }
        }

        reachable_profit_weight = alternative_weight;
        _maximal_profit = std::max(_maximal_profit, reachable_profit);
      }
    }
  }

  _solved = true;
}