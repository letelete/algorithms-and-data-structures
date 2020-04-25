
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

struct Graph {
  v<vint> representation;

  void create(int n) { representation = v<vint>(n); }

  void add_undirected_edge(int from, int to) {
    representation[from].push_back(to);
    representation[to].push_back(from);
  }
} graph;

vint tree_centers() {
  int n = graph.representation.size();
  vint degree(n, 0);
  vint leaves;
  for (int i = 0; i < n; ++i) {
    auto node = graph.representation[i];
    degree[i] = node.size();
    if (degree[i] <= 1) {
      leaves.push_back(i);
      degree[i] = 0;
    }
  }
  int count = leaves.size();
  while (count < n) {
    vint new_leaves;
    for (auto& node : leaves) {
      for (auto& neighbour : graph.representation[node]) {
        degree[neighbour]--;
        if (degree[neighbour] == 1) {
          new_leaves.push_back(neighbour);
        }
      }
      degree[node] = 0;
    }
    leaves = new_leaves;
    count += leaves.size();
  }
  return leaves;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  graph.create(10);
  graph.add_undirected_edge(0, 1);
  graph.add_undirected_edge(1, 4);
  graph.add_undirected_edge(1, 3);
  graph.add_undirected_edge(3, 2);
  graph.add_undirected_edge(3, 6);
  graph.add_undirected_edge(3, 7);
  graph.add_undirected_edge(6, 9);
  graph.add_undirected_edge(4, 8);
  graph.add_undirected_edge(4, 5);

  for (auto& x : tree_centers()) std::cout << x << " ";
  std::cout << "\n";

  return 0;
}
