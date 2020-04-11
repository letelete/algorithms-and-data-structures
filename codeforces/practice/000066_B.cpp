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

int main() {
  fastIO;

  int n;
  std::cin >> n;
  vint stages(n);
  for (int& x : stages) std::cin >> x;

  int best = 1, last_pitfall = 0, count = 1;
  for (int i = 1; i < n; ++i) {
    if (stages[i - 1] >= stages[i]) {
      if (stages[i - 1] > stages[i]) last_pitfall = i;
      count++;
    } else {
      count++;
    }
    if (i + 1 == n || stages[i + 1] > stages[i] && stages[i - 1] >= stages[i]) {
      best = std::max(best, count);
      count = i - last_pitfall + 1;
    }
  }

  std::cout << best << "\n";

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
