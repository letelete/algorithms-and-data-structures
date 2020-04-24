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

const char WATER = 'w';
const char LAND = 'l';

int n, m, x, y;

vstr grid;
v<v<bool>> vis;

vint dx{{-1, 0, 1, 0}};
vint dy{{0, 1, 0, -1}};

void dfs(int x, int y, int& count) {
  if (grid[x][y] == WATER || vis[x][y]) return;
  vis[x][y] = true;
  count++;
  for (int i = 0; i < dx.size(); ++i) {
    int next_x = x + dx[i];
    int next_y = y + dy[i];
    if (next_x < 0 || next_x >= n) continue;
    if (next_y >= m) next_y = 0;
    if (next_y < 0) next_y = m - 1;
    dfs(next_x, next_y, count);
  }
}

int main() {
  fastIO;

  while (std::cin >> n >> m) {
    grid = vstr(n);
    vis = v<v<bool>>(n, v<bool>(m));
    for (auto& x : grid) std::cin >> x;
    std::cin >> x >> y;

    int king_land = 0;
    dfs(x, y, king_land);

    int max_land = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int next_land = 0;
        dfs(i, j, next_land);
        max_land = std::max(max_land, next_land);
      }
    }

    std::cout << max_land << "\n";
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
