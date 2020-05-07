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

int n, m, queries;

struct node {
  int color;
  int id;
};

v<v<node>> g;
v<uset<int>> vis;
uset<int> colors;

void dfs(int node_id, int final_id, int color = 0) {
  if (node_id == final_id) {
    colors.insert(color);
    return;
  }
  for (const auto& next : g[node_id]) {
    int next_color = color ? color : next.color;

    if (vis[next.id].count(next_color)) continue;
    if (next_color != next.color) continue;

    vis[next.id].insert(next_color);
    dfs(next.id, final_id, next_color);
  }
}

int main() {
  fastIO;

  std::cin >> n >> m;

  g = v<v<node>>(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    g[a].push_back(node{c, b});
    g[b].push_back(node{c, a});
  }

  std::cin >> queries;

  while (queries--) {
    int from, to;
    std::cin >> from >> to;

    vis = v<uset<int>>(n + 1);
    for (const auto& x : g[from]) vis[from].insert(x.color);
    colors.clear();

    dfs(from, to);
    std::cout << colors.size() << "\n";
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
