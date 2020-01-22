/**
 * Jaskinia diamentów
 *
 * Stowarzyszenie Talent
 * G16, etap 2, dzień dzień B. Dostępna pamięć: 64 MB. 04.2015
 *
 * https://szkopul.edu.pl/c/archiwum-zadan-k0mpend1x/problemset/problem/y2gdhCAB0TaLwumvZIyKKFd3/site/?key=statement
 *
 * Score: Unknown - The task has been archived.
 * Time complexity: 
 * Prefix sum 2d vector initialization: O(n^2)
 * Single rect query O(1)
 */
#include <bits/stdc++.h>

#define MAX_N 1000
#define MAX_A 1000000
#define MAX_K 1000000

namespace cp {
void optimize_io() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);
}

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

typedef std::string str;

template <class T>
T pow(T a, unsigned b = 2) {
  if (b == 0) return 1;
  unsigned temp = pow(a, b / 2);
  if (b % 2 == 0) return temp * temp;
  return a * temp * temp;
}
}  // namespace cp

using namespace cp;

v<v<int>> sums;

struct point {
  int x, y;
};

struct rect {
  point left_top, bottom_right;
};

int solve(rect& r) {
  int raw_sum = sums[r.bottom_right.y][r.bottom_right.x];
  if (r.left_top.y >= 1) raw_sum -= sums[r.left_top.y - 1][r.bottom_right.x];
  if (r.left_top.x >= 1) raw_sum -= sums[r.bottom_right.y][r.left_top.x - 1];
  if (r.left_top.x >= 1 && r.left_top.y >= 1) {
    raw_sum += sums[r.left_top.y - 1][r.left_top.x - 1];
  }
  return raw_sum;
}

int main() {
  optimize_io();

  int x, y;
  std::cin >> y >> x;

  sums = v<v<int>>(y, v<int>(x));

  for (int i = 0; i < y; i++) {
    for (int j = 0, in; j < x; j++) {
      std::cin >> in;
      if (j >= 1) in += sums[i][j - 1];
      if (i >= 1) in += sums[i - 1][j];
      if (i >= 1 && j >= 1) in -= sums[i - 1][j - 1];
      sums[i][j] = in;
    }
  }

  int k;
  std::cin >> k;

  int max_profit = 0;
  for (int i = 0, x, y, xx, yy; i < k; i++) {
    std::cin >> y >> x >> yy >> xx;
    rect cur_rect{{x - 1, y - 1}, {xx - 1, yy - 1}};
    max_profit = max(max_profit, solve(cur_rect));
  }

  std::cout << max_profit << "\n";

  return 0;
}