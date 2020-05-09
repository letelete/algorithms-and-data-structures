#include "../include/bounded_knapsack_solver.hh"
#include "../include/input.hh"

Input* input;
BoundedKnapsackSolver* solver;

void initialize() {
  input = new Input();

  auto knapsack = input->generate_knapsack();
  auto items = input->generate_items();

  solver = new BoundedKnapsackSolver(knapsack, items);
  solver->solve();
}

int main() {
  initialize();

  input->print_knapsack();
  input->print_generated_items();

  solver->print_most_profitable_items();
  solver->print_maximal_profit();

  return 0;
}