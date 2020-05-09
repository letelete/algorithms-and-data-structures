#include "../include/bounded_knapsack_solver.hh"

#include <iostream>
#include <map>
#include <numeric>

void BoundedKnapsackSolver::print_maximal_profit() {
  std::cout << "You've earned " << maximal_profit << " $\n";
  int lost = calculate_maximal_items_value() - maximal_profit;
  if (!lost) return;
  std::cout << "And because of your knapsack limits, you've lost items worth "
            << lost << " $\n";
}

void BoundedKnapsackSolver::print_most_profitable_items() {
  if (most_profitable_items.empty()) return;
  std::cout << "All items were worth " << calculate_maximal_items_value()
            << " $\n";
  std::cout << "And here is the most profitable combination of them\n";
  printer->printItemsHorizontally(most_profitable_items);
}

void BoundedKnapsackSolver::solve() {
  if (items.empty()) return;
  if (knapsack.capacity <= 0) return;

  /**
   * We will mark an illegal cell with -1 value to identify that we cannot build
   * on top of it.
   */
  const int ILLEGAL = -1;

  int absolute_items_size = items.size() + 1;

  /** Two dimensional table representing dynamic programming states of
   * possible weights for the first i-th elements with given j-th price.
   * where:
   * - i - minimal amount of numbers required to get a profit of j
   * - j - maximal profit for the first i-th items
   */
  std::vector<std::vector<int>> dp(
      absolute_items_size,
      std::vector<int>(calculate_maximal_items_value() + 1, ILLEGAL));

  // The base case is a state, where we didn't use any of items, so all are free
  for (int i = 0; i < absolute_items_size; ++i) dp[i][0] = 0;

  for (int i = 1; i < absolute_items_size; ++i) {
    Item item = items[i - 1];
    int item_copies_left = item.quantity;
    while (item_copies_left--) {
      for (int j = maximal_profit; j >= 0; --j) {
        if (dp[i][j] == ILLEGAL) continue;

        int reachable_profit = j + item.cost;
        int alternative_weight = dp[i][j] + item.weight;
        int& reachable_weight = dp[i][reachable_profit];

        if (reachable_weight > knapsack.capacity) continue;

        bool override_price = reachable_weight == ILLEGAL ||
                              reachable_weight > alternative_weight;
        if (override_price) {
          reachable_weight = alternative_weight;
          maximal_profit = std::max(maximal_profit, reachable_profit);
        }
      }
    }
  }
}

int BoundedKnapsackSolver::calculate_maximal_items_value() {
  if (maximal_items_value != -1) return maximal_items_value;
  return std::accumulate(items.begin(), items.end(), 0,
                         [&](int sum, const Item& item) {
                           return sum + (item.cost * item.weight);
                         });
}