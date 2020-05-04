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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, min = INT_MAX, max = INT_MIN, saved = 0;
  std::cin >> n;
  vint nums(n);
  for (auto& x : nums) {
    std::cin >> x;
    min = std::min(min, x);
    max = std::max(max, x);
  }
  if (min * 2 >= max) {
    std::cout << "0\n";
    return 0;
  }
  q<int> range;
  std::sort(nums.begin(), nums.end());
  for (const auto& x : nums) {
    while (!range.empty() && range.front() * 2 < x) range.pop();
    saved = std::max(range.size() + 1, (unsigned)saved);
    range.push(x);
  }
  std::cout << (n - saved) << "\n";

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
