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

  int extended_items_value = maximal_items_value() + 1;
  _weight_at_price = std::vector<int>(extended_items_value, _UNREACHABLE_PRICE);

  // The base case is a state, where we didn't use any of _items, so all are
  // free
  _weight_at_price[0] = 0;

  for (const auto& item : _items) {
    int copies_left = item->quantity;
    while (copies_left--) {
      for (int price = _maximal_profit; price >= 0; --price) {
        if (_weight_at_price[price] == _UNREACHABLE_PRICE) continue;
        _update_weight_price(item, price);
      }
    }
  }

  _solved = true;
}

void BoundedKnapsackSolver::_update_weight_price(Item* item, int price) {
  int reachable_price = price + item->cost;
  int alternative_weight = _weight_at_price[price] + item->weight;
  int& reachable_price_weight = _weight_at_price[reachable_price];

  bool weight_overload = alternative_weight > _knapsack->capacity;
  bool dont_override_price = (reachable_price_weight != _UNREACHABLE_PRICE) &&
                             (reachable_price_weight <= alternative_weight);
  if (weight_overload || dont_override_price) return;

  _update_price_relation(item, price, reachable_price);

  reachable_price_weight = alternative_weight;
  _maximal_profit = std::max(_maximal_profit, reachable_price);
}

void BoundedKnapsackSolver::_update_price_relation(Item* reached_with,
                                                   int current_price,
                                                   int reachable_price) {
  Item* item = reached_with;
  item->quantity = 1;

  auto& reachable_relation = _price_relation[reachable_price];

  if (reachable_price != _UNREACHABLE_PRICE) {
    reachable_relation = _price_relation[current_price];
    if (!reachable_relation.empty() && (*reachable_relation.top() == *item)) {
      reachable_relation.top()->quantity++;
      return;
    }
  }

  reachable_relation.push(item);
}