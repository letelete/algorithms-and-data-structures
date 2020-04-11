#include <bits/stdc++.h>
#pragma GCC target("popcnt")
#define fastIO      \
  std::cin.tie(0);  \
  std::cout.tie(0); \
  std::ios::sync_with_stdio(0);
template <typename T>
using q = std::queue<T>;
template <typename T>
using pq = std::priority_queue<T>;
template <typename T>
using set = std::set<T>;
template <typename T>
using uset = std::unordered_set<T>;
typedef long long int i64;
typedef unsigned long long ui64;
typedef std::vector<int> vint;
typedef std::vector<char> vchar;
typedef std::vector<std::string> vstr;
typedef std::pair<int, int> pint;
template <typename T>
using stack = std::stack<T>;
template <typename T>
using v = std::vector<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
template <typename K, typename V>
using map = std::map<K, V>;
typedef std::string str;

const int NODES = 3;

map<char, v<char>> g;
umap<char, bool> visited;

void mark_with_dfs(char node, str& order) {
  if (visited[node]) return;
  visited[node] = true;
  for (auto& x : g[node]) {
    mark_with_dfs(x, order);
  }
  order.push_back(node);
}

str solve() {
  str order;
  for (auto& next : g) {
    mark_with_dfs(next.first, order);
  }
  return order;
}

int impossible() {
  std::cout << "Impossible\n";
  return 0;
}

int main() {
  fastIO;

  int entries = NODES;
  str entry;

  int count = 0;
  while (entries--) {
    std::cin >> entry;
    char parent = entry[0];
    char child = entry[2];
    if (entry[1] == '<') std::swap(parent, child);
    for (const auto& x : g[child]) {
      if (x == parent) return impossible();
    }
    g[parent].push_back(child);
    if (g[parent].size() == 1) count++;
  }

  if (count == NODES) return impossible();

  std::cout << solve() << "\n";
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
