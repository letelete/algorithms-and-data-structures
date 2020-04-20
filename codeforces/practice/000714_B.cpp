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
  set<int> nums;
  while (n--) {
    int x;
    std::cin >> x;
    nums.insert(x);
  }
  auto it = nums.begin();
  int cur_diff = *(++it) - *(std::prev(it));
  int diff = *(std::prev(nums.end())) - *(nums.begin());
  for (; it != nums.end(); ++it) {
    auto prev = std::prev(it);
    if (*it == *(prev)) continue;
    if (*it - *prev != cur_diff || (cur_diff * 2 != diff && cur_diff != diff)) {
      std::cout << "NO\n";
      return 0;
    }
  }
  std::cout << "YES\n";

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
