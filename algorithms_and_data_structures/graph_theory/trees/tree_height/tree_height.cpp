
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

int nodes, sum, root;

umap<int, vint> tree;
std::queue<int> tovisit;

int max_height = -1;
int left_in_layer = 1;
int next_layer_nodes = 0;

void solve() {
  tovisit.push(root);
  while (!tovisit.empty()) {
    int node = tovisit.front();
    tovisit.pop();
    for (const auto& x : tree[node]) {
      tovisit.push(x);
      next_layer_nodes++;
    }
    --left_in_layer;
    if (!left_in_layer) {
      left_in_layer = next_layer_nodes;
      next_layer_nodes = 0;
      ++max_height;
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

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
  if (!nodes) max_height = 0;
  else solve();
  std::cout << max_height << "\n";

  return 0;
}
