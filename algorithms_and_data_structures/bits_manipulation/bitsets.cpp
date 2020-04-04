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

const int MAX_DAY = 31;
const int MAX_N = 5001;

int main() {
  fastIO;

  int n;
  std::cin >> n;
  v<std::bitset<MAX_DAY>> workers(n, 0);

  for (int i = 0; i < n; ++i) {
    int m;
    std::cin >> m;
    while (m--) {
      int y;
      std::cin >> y;
      workers[i] |= (1 << y);
    }
  }

  pint best_workers{-1, -1};
  int days = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int next_days = (workers[i] & workers[j]).count();
      if (next_days > days) {
        best_workers = std::make_pair(i, j);
        days = next_days;
      }
    }
  }

  std::cout << days << "\n";
  std::cout << best_workers.first + 1 << " " << best_workers.second + 1 << "\n";

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
