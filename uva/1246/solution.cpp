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

int n, m;
v<vint> graph;
v<bool> visited;

void sort_dag(int node, vint& order) {
  if (visited[node]) return;
  visited[node] = true;
  for (auto& child : graph[node]) {
    sort_dag(child, order);
  }
  order.push_back(node);
}

int main() {
  fastIO;
  while (std::cin >> n >> m && n != 0) {
    graph = v<vint>(n + 1);
    visited = v<bool>(n + 1, false);
    while (m--) {
      int parent, child;
      std::cin >> parent >> child;
      graph[parent].push_back(child);
    }
    vint order;
    for (int i = 1; i < graph.size(); ++i) {
      sort_dag(i, order);
    }
    std::reverse(order.begin(), order.end());
    for (const auto& x : order) std::cout << x << " ";
    std::cout << "\n";
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
