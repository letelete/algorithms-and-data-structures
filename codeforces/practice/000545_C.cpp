#include <bits/stdc++.h>

#pragma GCC target("popcnt")

#define fastIO      \
  std::cin.tie(0);  \
  std::cout.tie(0); \
  std::ios::sync_with_stdio(0);

template <typename T>
using v = std::vector<T>;
template <typename T>
using q = std::queue<T>;
template <typename T>
using pq = std::priority_queue<T>;
template <typename T>
using set = std::set<T>;
template <typename T>
using uset = std::unordered_set<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
template <typename K, typename V>
using map = std::map<K, V>;
template <typename T, typename K>
using pair = std::pair<T, K>;

typedef long long int i64;
typedef unsigned long long ui64;

typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<char> vchar;
typedef std::vector<std::string> vstr;
typedef std::pair<int, int> pint;

enum states { L = 0, R = 1, C = 2 };

int main() {
  fastIO;

  int n;
  std::cin >> n;
  vint h(n + 1), x(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> x[i] >> h[i];

  v<vint> dp(n + 1, vint(3, 0));
  dp[1][L] = 1;

  auto sum_row = [&dp](int index) {
    return std::max(dp[index][L], std::max(dp[index][R], dp[index][C]));
  };

  for (int i = 1; i <= n; ++i) {
    int max_prev = sum_row(i - 1);
    dp[i][C] = max_prev;
    if (i >= n || x[i] + h[i] < x[i + 1]) dp[i][R] = max_prev + 1;
    if (x[i] - h[i] > x[i - 1]) {
      dp[i][L] = std::max(dp[i - 1][L], dp[i - 1][C]) + 1;
      if (x[i] - h[i] > x[i - 1] + h[i - 1]) {
        dp[i][L] = std::max(dp[i][L], dp[i - 1][R] + 1);
      }
    }
  }

  std::cout << sum_row(n) << "\n";

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */

/** ⚠ Common mistakes
 * 1. No checking for integer overflow in the addition operation
 * (use i64 instead)
 */
