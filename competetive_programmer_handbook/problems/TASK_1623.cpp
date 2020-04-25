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

  vint nums(n);
  i64 n_sum = 0, diff = INT_MAX;
  for (auto& x : nums) {
    std::cin >> x;
    n_sum += x;
  }

  for (int m = 0; m < (1 << n); ++m) {
    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
      if ((m >> i) & 1) sum += nums[i];
    }
    i64 second_sum = n_sum - sum;
    if (second_sum > sum) std::swap(second_sum, sum);
    diff = std::min(diff, sum - second_sum);
  }

  std::cout << diff << "\n";

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
