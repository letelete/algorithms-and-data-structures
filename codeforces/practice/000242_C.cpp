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

vint dx{{-1, 0, 1, 0, -1, -1, 1, 1}};
vint dy{{0, 1, 0, -1, -1, 1, -1, 1}};

int x_from, y_from, x_to, y_to, n;
map<pint, bool> grid;

i64 bfs() {
  pint parent{x_from, y_from};
  q<pint> nodes{{parent}};

  i64 steps = 0;
  i64 curr_layer = nodes.size();
  i64 next_layer = 0;

  while (!nodes.empty()) {
    parent = nodes.front();
    nodes.pop();
    grid[parent] = false;

    for (int i = 0; i < dx.size(); ++i) {
      pint child = {parent.first + dx[i], parent.second + dy[i]};
      if (grid.find(child) == grid.end() || !grid[child]) continue;
      if (child.first == x_to && child.second == y_to) return steps + 1;
      nodes.push(child);
      next_layer++;
    }

    if (!--curr_layer) {
      curr_layer = next_layer;
      next_layer = 0;
      steps++;
    }
  }

  return -1;
}

int main() {
  fastIO;

  std::cin >> x_from >> y_from >> x_to >> y_to >> n;
  if (x_from == x_to && y_from == y_to) {
    std::cout << "0\n";
    return 0;
  }

  while (n--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    for (; b <= c; ++b) {
      grid.insert({std::make_pair(a, b), true});
    }
  }

  std::cout << bfs() << "\n";

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
