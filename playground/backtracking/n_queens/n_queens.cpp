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

int n, count;
v<v<bool>> grid;

vint dx{{-1, -1, -1}};
vint dy{{0, -1, 1}};

bool valid_coords(int x, int y) {
  return ((x >= 0 && x < n) && (y >= 0 && y < n));
}

bool dangerous(int x, int y) {
  for (unsigned i = 0; i < dx.size(); ++i) {
    int next_x = x, next_y = y;
    while (valid_coords(next_x, next_y)) {
      if (grid[next_x][next_y]) return true;
      next_x += dx[i];
      next_y += dy[i];
    }
  }
  return false;
}

void solve_n_qeens(int x = 0) {
  if (x == n) {
    count++;
    return;
  }
  for (int y = 0; y < n; ++y) {
    if (dangerous(x, y)) continue;
    grid[x][y] = 1;
    solve_n_qeens(x + 1);
    grid[x][y] = 0;
  }
}

int main() {
  fastIO;

  std::cin >> n;
  grid = v<v<bool>>(n, v<bool>(n, false));
  count = 0;

  solve_n_qeens();
  std::cout << count << "\n";

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
