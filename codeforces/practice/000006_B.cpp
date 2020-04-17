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

vint rd{{0, 1, 0, -1}};
vint cd{{-1, 0, 1, 0}};

int main() {
  fastIO;

  int n, m;
  char p;
  std::cin >> n >> m >> p;

  v<str> grid(n);
  bool p_seen = false;
  int px = 0, py = 0;

  for (auto& x : grid) {
    std::cin >> x;
    for (int j = 0; j < m; ++j) {
      if (p_seen) continue;
      if (x[j] == p) {
        p_seen = true;
        px = j;
        break;
      }
    }
    py += !p_seen;
  }

  std::unordered_set<char> deputy;

  for (int i = py; i < n; ++i) {
    if (grid[i][px] != p) break;
    for (int j = px; j < m; ++j) {
      if (grid[i][j] != p) break;
      for (int dir = 0; dir < 4; ++dir) {
        int y = i + cd[dir];
        int x = j + rd[dir];
        if (y < 0 || y >= n) continue;
        if (x < 0 || x >= m) continue;
        if (grid[y][x] == '.') continue;
        deputy.insert(grid[y][x]);
      }
    }
  }

  std::cout << (deputy.size() - deputy.count(p)) << "\n";

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
