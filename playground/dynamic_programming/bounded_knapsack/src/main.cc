#include <vector>

#include "../include/bounded_knapsack_solver.hh"
#include "../include/input.hh"

const std::string new_section_separator = "\n-------\n\n";

Input* input;
PrettyPrinter* printer;
BoundedKnapsackSolver* solver;

int main() {
  input = new Input();
  printer = new PrettyPrinter();

  auto knapsack = input->generate_knapsack();
  auto items = input->generate_items();
  solver = new BoundedKnapsackSolver(knapsack, items);

  std::cout << "Your knapsack has " << knapsack->capacity
            << " kg of capacity\n";

  std::cout << "You have " << items.size()
            << " unique items available with a total cost of "
            << solver->maximal_items_value() << " $\n";

  printer->print_items_horizontally(items);

  std::cout << new_section_separator;

  std::cout << "By selecting following items you will earn "
            << solver->maximal_profit() << " $\n\n";

  printer->print_items_horizontally(solver->most_profitable_items());

  std::cout << "That's the highest possible profit you can get :)\n";

  return 0;
}