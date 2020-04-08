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

  int t, n, m;
  std::cin >> t;
  while (t--) {
    std::cin >> m >> n;
    bool black = true;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((n % 2 == 0 && i == m - 1 && j == n - 1) ||
            (m % 2 == 0 && i == m - 1 && j == 0)) {
          std::cout << "B";
        } else {
          std::cout << (black ? "B" : "W");
        }
        black = !black;
      }
      if (n % 2 == 0) black = !black;
      std::cout << "\n";
    }
  }

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
