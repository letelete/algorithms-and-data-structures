#include <bits/stdc++.h>
template <typename T>
using v = std::vector<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
typedef long long int i64;
typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<std::string> vstr;
typedef std::vector<char> vchar;
typedef std::pair<int, int> pint;

int n, m, bench {0};
v<vint> g;
v<bool> vis;
std::unordered_set<int> team_a, team_b;

void dfs(int node) {
  if (vis[node]) return;

  vis[node] = true;
  bool a_empty = true, b_empty = true;
  for (const int& next : g[node]) {
    if (team_a.count(next)) a_empty = false;
    if (team_b.count(next)) b_empty = false;
  }

  if (a_empty) team_a.insert(node);
  else if (b_empty) team_b.insert(node);
  else bench++;

  for (const int& next : g[node]) dfs(next);
}

int solve() {
  int players = n - bench;
  return bench + (players % 2 != 0);
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> n >> m;
  vis = v<bool>(n + 1, false);
  g = v<vint>(n + 1);
  for (int i = 0, p, c; i < m; ++i) {
    std::cin >> p >> c;
    g[p].push_back(c);
    g[c].push_back(p);
  }

  for (int i = 1; i <= n; ++i) dfs(i);

  std::cout << solve() << "\n";
}
