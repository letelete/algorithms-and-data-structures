#include <bits/stdc++.h>

namespace cp {
void optimize_io() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);
}

typedef std::string str;

typedef long long int i64;

template <typename T>
using v = std::vector<T>;

template <typename K, typename V>
using umap = std::unordered_map<K, V>;

template <class T>
T min(T a, T b) {
  return a > b ? b : a;
}

template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}

template <class T>
T pow(T a, unsigned b = 2) {
  if (b == 0) return 1;
  unsigned temp = pow(a, b / 2);
  if (b % 2 == 0) return temp * temp;
  return a * temp * temp;
}
}  // namespace cp

using namespace cp;

#define MIN_TEMP -1e9
#define MAX_TEMP 1e9

struct temp {
  i64 min, max;
};

int days_amount;

v<temp> days;

int solve() {
  int left = 0, right = 1, max_days = 1;
  i64 last_temp = days[left].min;

  while (right < days.size()) {
    temp day = days[right];
    if (day.max >= last_temp) {
      if (day.min > last_temp) last_temp = day.min;
      max_days = max(max_days, right - left + 1);
    } else {
      last_temp = day.min;
      left = right;
    }
    ++right;
  }

  return max_days;
}

int main() {
  optimize_io();

  std::cin >> days_amount;

  days = v<temp>(days_amount);
  for (temp& day : days) std::cin >> day.min >> day.max;

  std::cout << solve() << "\n";

  return 0;
}