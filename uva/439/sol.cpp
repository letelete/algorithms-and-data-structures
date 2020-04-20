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

vint cmv{{-1, 0, 1, 0, -1, -1, 1, 1}};
vint rmv{{0, 1, 0, -1, -1, 1, -1, 1}};

v<vstr> grid;

void generate_grid() {
  grid = v<vstr>(8, vstr(8));
  int col = 0;
  for (int i = 8; i >= 1; --i) {
    int row = 0;
    for (char j = 'a'; j <= 'h'; ++j) {
      grid[col][row].push_back(j);
      grid[col][row].push_back(i + '0');
      ++row;
    }
    ++col;
  }
}

pint index_of(str node) {
  int col = 8 - (int)(node[1] - '0');
  int row = node[0] - 'a';
  return std::make_pair(col, row);
}

int solve(str from, str to) {
  uset<str> vis{{from}};
  q<str> nodes{{from}};

  int l = 0;
  int in = 1;
  int next = 0;

  while (!nodes.empty()) {
    str parent = nodes.front();
    pint pxy = index_of(parent);
    nodes.pop();
    vis.insert(parent);

    if (parent == to) return l;

    for (int i = 0; i < cmv.size(); ++i) {
      int next_col = pxy.first + cmv[i];
      int next_row = pxy.second + rmv[i];
      if (next_col < 0 || next_col >= grid.size()) continue;
      if (next_row < 0 || next_row >= grid.size()) continue;
      if (vis.count(grid[next_col][next_row])) continue;
      nodes.push(grid[next_col][next_row]);
      next++;
    }

    in--;
    if (!in) {
      in = next;
      next = 0;
      l++;
    }
  }

  return 0;
}

int main() {
  fastIO;

  generate_grid();

  str from, to;
  while (std::cin >> from >> to) {
    int ans = solve(from, to);

    std::cout << "To get from " << from << " to " << to << " takes " << ans
              << " knight moves.\n";
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
