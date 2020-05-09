#include "bounded_knapsack_solver.hh"
#include "input.hh"

Input* input;
BoundedKnapsackSolver* boundedKnapsackSolver;

void initialize() {
  input = new Input();

  auto knapsack = input->generate_knapsack();
  auto items = input->generate_items();

  boundedKnapsackSolver = new BoundedKnapsackSolver(knapsack, items);
}

int main() {
  initialize();
  boundedKnapsackSolver->print_maximal_profit();
  return 0;
}