#include "../include/bounded_knapsack_solver.hh"

#include <iostream>
#include <numeric>

void BoundedKnapsackSolver::print_maximal_profit() {
  std::cout << "Maximal profit: " << maximal_profit << "\n\n";
}

void BoundedKnapsackSolver::print_most_profitable_items() {
  if (most_profitable_items.empty()) return;
  std::cout << "Most profitable items:\n";
  for (auto& it : most_profitable_items) it.print();
  std::cout << "\n";
}

void BoundedKnapsackSolver::solve() {
  if (items.empty()) return;
  if (knapsack.capacity <= 0) return;

  /**
   * We will mark an illegal cell with -1 value to identify that we cannot build
   * on top of it.
   */
  const int ILLEGAL = -1;

  int max_possible_profit = std::accumulate(
      items.begin(), items.end(), 0, [&](int sum, const Item& item) {
        return sum + (item.cost * item.weight);
      });

  int absolute_items_size = items.size() + 1;

  /** Two dimensional table representing dynamic programming states of
   * possible weights for the first i-th elements with given j-th price.
   * where:
   * - i - minimal amount of numbers required to get a profit of j
   * - j - maximal profit for the first i-th items
   */
  std::vector<std::vector<int>> dp(
      absolute_items_size, std::vector<int>(max_possible_profit + 1, ILLEGAL));

  // The base case is a state, where we didn't use any of items, so we dispose
  // all of them.
  for (int i = 0; i < absolute_items_size; ++i) dp[i][0] = 0;

  int maximal_profit = 0;

  for (int i = 1; i < absolute_items_size; ++i) {
    Item& item = items[i];
    while (item.quantity--) {
      for (int j = maximal_profit; j >= 0; ++j) {
        if (dp[i][j] == ILLEGAL) continue;

        int reachable_profit = j + item.cost;
        int& reachable_items_weight = dp[i][reachable_profit];
        if (reachable_items_weight == ILLEGAL) {
          reachable_items_weight = item.weight;
        } else {
          int alternative_weight = dp[i][j] + item.weight;
          int reachable_items_weight =
              std::min(reachable_items_weight, alternative_weight);
        }

        maximal_profit = std::max(maximal_profit, reachable_profit);
      }
    }
  }
}