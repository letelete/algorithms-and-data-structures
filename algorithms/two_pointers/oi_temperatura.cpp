#include <bits/stdc++.h>

template <typename T>
T max(T a, T b) {
  return a >= b ? a : b;
};

struct temperature {
  long long int min, max;
};

int days;
std::vector<temperature> temperatures;

int longest_nondecreasing_temperature() {
  int left = 0, right = 1, longest = 1;
  long long int min_temp_limit = temperatures[0].min;

  while (right < temperatures.size()) {
    temperature& cur = temperatures[right];
    if (cur.max >= min_temp_limit) {
      min_temp_limit = max(min_temp_limit, cur.min);
      int window_size = right - left + 1;
      longest = max(longest, window_size);
    } else {
      right = ++left;
      min_temp_limit = temperatures[right].min;
    }
    ++right;
  }

  return longest;
}

int main() {
  std::cin >> days;
  temperatures = std::vector<temperature>(days);

  for (temperature& t : temperatures) {
    std::cin >> t.min >> t.max;
  }

  std::cout << longest_nondecreasing_temperature() << "\n";

  return 0;
}