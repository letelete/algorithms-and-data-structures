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

int n, m, k, t, c, r;

i64 get_index(int c, int r) { return (m * (c - 1)) + r; }

umap<int, str> mod_res{{0, "Grapes"}, {1, "Carrots"}, {2, "Kiwis"}};

int main() {
  fastIO;
  std::cin >> n >> m >> k >> t;
  set<i64> grid;

  int lastc = 0, lastr = 0;
  while (k--) {
    std::cin >> c >> r;
    grid.insert(get_index(c, r));
  }

  while (t--) {
    std::cin >> c >> r;
    str msg = "Waste";
    i64 index = get_index(c, r);
    if (grid.find(index) == grid.end()) {
      auto it = grid.lower_bound(index);
      i64 count = std::distance(grid.begin(), it) -;
      msg = mod_res[(index - count) % 3];
    }
    std::cout << msg << "\n";
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
