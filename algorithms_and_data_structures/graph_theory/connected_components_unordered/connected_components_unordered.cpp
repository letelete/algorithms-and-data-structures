#include <bits/stdc++.h>
typedef long long int i64;
template <typename T>
using v = std::vector<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<std::string> vstr;
typedef std::vector<char> vchar;
typedef std::pair<int, int> pint;

int nodes;
umap<char, v<char>> graph;

v<v<char>> groups;

std::unordered_set<char> seen;

void dfs(char node_id, int group) {
  if (seen.count(node_id)) return;

  groups[group].push_back(node_id);
  seen.insert(node_id);

  for (auto& node : graph[node_id]) {
    dfs(node, group);
  }
}

void solve() {
  int group = 0;
  for (const auto& node : graph) {
    char node_id = node.first;
    if (seen.count(node_id)) {
      group++;
      continue;
    }
    dfs(node_id, group);
    group++;
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> nodes;
  groups = v<v<char>>(nodes);

  for (int i = 0; i < nodes; ++i) {
    char node_id;
    int connections;
    std::cin >> node_id >> connections;
    graph[node_id] = v<char>(connections);
    for (char& x : graph[node_id]) std::cin >> x;
  }

  solve();

  for (int i = 0; i < nodes; ++i) {
    if (groups[i].empty()) continue;
    std::cout << i << ": ";
    for (const auto& id : groups[i]) {
      std::cout << id << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
