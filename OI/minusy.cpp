/**
 * Minusy
 * IX OI stage III. Memory limit: 256 MB.
 * Score: 100/100
 *
 * https://szkopul.edu.pl/problemset/problem/POAyCWzUB990_g4_MA4GF9Jw/site/?key=statement
 */

#include <bits/stdc++.h>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int input_length;
  std::cin >> input_length;

  char op;
  bool bracket_openned;
  std::string result = "";

  for (int i = 0; i < (input_length - 1); i++) {
    std::cin >> op;
    if (op == '-') {
      if (bracket_openned) {
        result += ")-";
        bracket_openned = false;
      } else {
        result += "-";
      }
    } else {
      if (bracket_openned) {
        result += "-";
      } else {
        result += "(-";
        bracket_openned = true;
      }
    }
  }
  if (bracket_openned) {
    result += ")";
  }

  std::cout << result << "\n";

  return 0;
}
