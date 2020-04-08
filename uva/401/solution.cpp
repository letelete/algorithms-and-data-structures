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

  int tests;
  std::cin >> tests;
  for (int test = 0; test < tests; ++test) {
    vint l(4), r(4);
    for (int i = 0; i < l.size(); ++i) std::cin >> l[i];
    for (int i = 0; i < r.size(); ++i) std::cin >> r[i];
    int x1, y1, x2, y2;
    x1 = std::max(l[0], r[0]);
    y1 = std::max(l[1], r[1]);
    x2 = std::min(r[2], l[2]);
    y2 = std::min(r[3], l[3]);

    if (test > 0) std::cout << "\n";
    if (x1 < x2 && y1 < y2) {
      std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    } else {
      std::cout << "No Overlap\n";
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
