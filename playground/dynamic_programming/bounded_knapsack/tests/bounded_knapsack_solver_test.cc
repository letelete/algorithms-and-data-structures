#include "../include/bounded_knapsack_solver.hh"

#include <iostream>
#include <string>
#include <vector>

#include "../external/catch.hpp"
#include "../include/item.hh"
#include "../include/knapsack.hh"

bool vectors_equality(const std::vector<Item*>& a,
                      const std::vector<Item*>& b) {
  return std::equal(
      std::begin(a), std::end(a), std::begin(b),
      [](const Item* litem, const Item* ritem) { return *litem == *ritem; });
}

TEST_CASE("Single items' quantity") {
  Knapsack* knapsack = new Knapsack;
  Item* item_a = new Item;
  Item* item_b = new Item;
  Item* item_c = new Item;
  Item* item_d = new Item;

  *knapsack = {9};

  *item_a = {"A", 3, 2, 1};
  *item_b = {"B", 5, 3, 1};
  *item_c = {"C", 7, 4, 1};
  *item_d = {"D", 2, 2, 1};

  std::vector<Item*> items{{item_a, item_b, item_c, item_d}};

  BoundedKnapsackSolver* solver = new BoundedKnapsackSolver(knapsack, items);

  // Assuming, the knapsack capability equals 9 kg,
  // The highest possible profit can be achieved by combining items {A,B,C}
  // You can get the same weight of 9 kg by combining {B,C,D}, however that
  // won't produce the highest possible profit.
  int highest_possible_profit = 15;
  std::vector<Item*> most_profitable_items{{item_a, item_b, item_c}};
  std::sort(most_profitable_items.begin(), most_profitable_items.end());

  SECTION("The highest possible profit is computed") {
    REQUIRE(solver->maximal_profit() == highest_possible_profit);
  }

  SECTION("The most profitable items are constructed") {
    REQUIRE(vectors_equality(solver->most_profitable_items(),
                             most_profitable_items));
  }
}

TEST_CASE("Multiple items of one type") {
  Knapsack* knapsack = new Knapsack;
  Item* item_a = new Item;
  Item* item_b = new Item;
  Item* item_c = new Item;

  *knapsack = {8};

  *item_a = {"A", 17, 3, 3};
  *item_b = {"B", 15, 3, 1};
  *item_c = {"C", 18, 2, 2};

  std::vector<Item*> items{{item_a, item_b, item_c}};

  BoundedKnapsackSolver* solver = new BoundedKnapsackSolver(knapsack, items);

  // We should use item item 'A' once and item 'C' twice to get the
  // highest profit of 53
  int highest_possible_profit = 53;
  Item* item_a_after = item_a;
  Item* item_c_after = item_c;
  item_a_after->quantity = 1;
  item_c_after->quantity = 2;

  std::vector<Item*> most_profitable_items{{item_a_after, item_c_after}};
  std::sort(most_profitable_items.begin(), most_profitable_items.end());

  SECTION("The highest possible profit with multiple copies of single item") {
    REQUIRE(solver->maximal_profit() == highest_possible_profit);
  }

  SECTION("Shows items' quantity correctly") {
    REQUIRE(vectors_equality(solver->most_profitable_items(),
                             most_profitable_items));
  }
}