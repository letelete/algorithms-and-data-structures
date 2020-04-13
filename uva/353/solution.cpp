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

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}

double solve(vint& nums) {
  int n = nums.size();
  int count = 0, pairs = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      pairs++;
      int max = nums[i], min = nums[j];
      if (max < min) std::swap(max, min);
      if (gcd(max, min) == 1) ++count;
    }
  }
  if (!count) return 0;
  return sqrt(6.000000 * (n * (n - 1) / 2));
}

int main() {
  fastIO;

  int t;
  while (std::cin >> t && t) {
    vint nums(t);
    for (auto& x : nums) std::cin >> x;

    double ans = solve(nums);
    if (!ans)
      std::cout << "No estimate for this data set.\n";
    else
      std::cout << std::fixed << std::setprecision(6) << ans << "\n";
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
