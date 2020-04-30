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

int main() {
  fastIO;
  int n;
  std::cin >> n;
  v<vint> grid(n, vint(n));
  for (auto& x : grid) {
    for (auto& y : x) std::cin >> y;
  }
  for (int i = 1; i < n; ++i) grid[0][i] += grid[0][i - 1];
  for (int i = 1; i < n; ++i) grid[i][0] += grid[i - 1][0];
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      grid[i][j] += std::max(grid[i - 1][j], grid[i][j - 1]);
    }
  }
  std::cout << grid[n - 1][n - 1] << "\n";
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
