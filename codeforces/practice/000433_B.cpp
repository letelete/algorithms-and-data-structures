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

  int n, m, type, l, r;
  std::cin >> n;

  v<v<i64>> nums(3, v<i64>(n));

  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    nums[0][i] = nums[1][i] = nums[2][i] = x;
  }

  std::cin >> m;

  for (int i = 1; i < n; ++i) nums[1][i] += nums[1][i - 1];

  std::sort(nums[2].begin(), nums[2].end());
  for (int i = 1; i < n; ++i) nums[2][i] += nums[2][i - 1];

  while (m--) {
    std::cin >> type >> l >> r;
    i64 sum = nums[type][r - 1];
    if (l >= 2) sum -= nums[type][l - 2];
    std::cout << sum << "\n";
  }

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
