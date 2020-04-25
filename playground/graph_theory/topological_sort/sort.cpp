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

int nodes;

// Must be the Directed Acyclic Graph (DAG)
umap<char, vint> graph;
umap<char, bool> visited;

void mark_dfs(char x, v<char> &sorted) {
  if (visited[x]) return;
  visited[x] = true;
  for (auto &c : graph[x]) mark_dfs(c, sorted);
  sorted.push_back(x);
};

v<char> sort_topologically() {
  v<char> sorted;
  for (const auto &p : graph) {
    mark_dfs(p.first, sorted);
  }
  std::reverse(sorted.begin(), sorted.end());
  return sorted;
}

int main() {
  fastIO;

  int m;
  std::cin >> nodes >> m;
  while (m--) {
    int k;
    char parent, child;
    std::cin >> parent >> k;
    while (k--) {
      std::cin >> child;
      graph[parent].push_back(child);
    }
  }

  auto res = sort_topologically();
  for (const auto &x : res) std::cout << x << " ";
  std::cout << "\n";

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
