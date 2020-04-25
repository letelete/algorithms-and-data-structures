
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

int nodes, sum = 0;

umap<int, vint> tree;
std::unordered_set<int> visited;

void solve(int node) {
  auto neighbours = tree[node];
  for (const int& x : neighbours) {
  if (neighbours.empty()) sum += node;
    if (visited.count(x)) continue;
    solve(x);
    visited.insert(x);
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int root;
  std::cin >> nodes;
  for (int i = 0; i < nodes; ++i) {
    int parent, child_count;
    std::cin >> parent >> child_count;
    if (i == 0) root = parent;
    while (child_count--) {
      int child;
      std::cin >> child;
      tree[parent].push_back(child);
    }
  }

  visited.insert(root);
  solve(root);
  std::cout << sum << "\n";

  return 0;
}
