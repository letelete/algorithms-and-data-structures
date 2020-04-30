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

  int n, max = 0, root = -1;
  std::cin >> n;
  vint nums(n);
  for (auto& x : nums) std::cin >> x;

  vint dp(n, 1), seq(n, -1), lis;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] >= nums[i]) continue;
      if (dp[j] + 1 < dp[i]) continue;
      dp[i] = dp[j] + 1;
      seq[i] = j;
      if (dp[i] <= max) continue;
      max = dp[i];
      root = i;
    }
  }

  std::cout << max << "\n";
  while (root != -1) {
    lis.push_back(nums[root]);
    root = seq[root];
  }

  for (int i = lis.size() - 1; i >= 0; --i) {
    std::cout << lis[i] << (i ? " " : "\n");
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
