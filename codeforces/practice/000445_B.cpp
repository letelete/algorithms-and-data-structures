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

int n, m;

umap<int, vint> g;
umap<int, bool> vis;

void dfs(int node, int& count) {
  vis[node] = true;
  ++count;
  for (const auto& next : g[node]) {
    if (vis[next]) continue;
    dfs(next, count);
  }
}

int main() {
  fastIO;

  std::cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int from, to;
    std::cin >> from >> to;
    g[from].push_back(to);
    g[to].push_back(from);
  }

  i64 count = 1;
  for (const auto& x : g) {
    if (vis[x.first]) continue;
    int cnt = 0;
    dfs(x.first, cnt);
    count <<= (cnt - 1);
  }
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
