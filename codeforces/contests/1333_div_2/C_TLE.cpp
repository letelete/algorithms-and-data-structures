#include <bits/stdc++.h>
#pragma GCC target("popcnt")
#define fastIO      \
  std::cin.tie(0);  \
  std::cout.tie(0); \
  std::ios::sync_with_stdio(0);
#define endl "\n"
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
typedef long long int i64;
typedef unsigned long long ui64;
typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<char> vchar;
typedef std::vector<std::string> vstr;
typedef std::pair<int, int> pint;

const int MAXN = 200000;

int main() {
  fastIO;

  int n;
  std::cin >> n;

  v<i64> nums(n);
  for (i64& x : nums) std::cin >> x;

  i64 count = 0;
  v<i64> origin;
  uset<str> seen;
  for (int r = n - 1; r >= 0; --r) {
    origin.push_back(nums[r]);
    str cur;
    i64 cur_sum = 0;
    for (int i = origin.size() - 1; i >= 0; --i) {
      cur += std::to_string(origin[i]);
      cur_sum += origin[i];
      if (seen.count(cur) || cur_sum == 0) continue;
      ++count;
      seen.insert(cur);
    }
  }

  std::cout << count << "\n";

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */

/** ⚠ Common mistakes
 *
 */
