
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

  void print() {
    int index = 0;
    for (const auto& x : representation) {
      std::cout << index << ": ";
      for (const auto& y : x) std::cout << y << " ";
      std::cout << "\n";
      index++;
    }
  }
};

struct TreeNode {
  int id = -1;
  TreeNode* parent = nullptr;
  v<TreeNode*> children = {};
};

TreeNode* build_tree(Graph graph, TreeNode* node) {
  for (int child_id : graph.representation[node->id]) {
    if (node->parent != nullptr && child_id == node->parent->id) continue;
    TreeNode* child = new TreeNode{child_id, node};
    node->children.push_back(child);
    build_tree(graph, child);
  }
  return node;
}

TreeNode* root_tree(Graph graph, int root_id) {
  TreeNode* root = new TreeNode{root_id};
  return build_tree(graph, root);
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  Graph graph;
  graph.create(9);
  graph.add_undirected_edge(0, 1);
  graph.add_undirected_edge(1, 2);
  graph.add_undirected_edge(2, 6);
  graph.add_undirected_edge(4, 3);
  graph.add_undirected_edge(5, 3);
  graph.add_undirected_edge(3, 7);
  graph.add_undirected_edge(7, 6);
  graph.add_undirected_edge(8, 6);

  std::cout << "Created graph:\n";
  graph.print();
  std::cout << "\n";

  TreeNode* root = root_tree(graph, 6);

  std::cout << "Testing rooted tree layers:\n";
  std::cout << "// Rooted at 6 the tree should look like:\n"
               "//           6\n"
               "//        /  |  \\\n"
               "//       2   7   8\n"
               "//      /    |\n"
               "//     1     3\n"
               "//    /     / \\\n"
               "//   0     4   5\n\n";

  std::queue<TreeNode*> nodes_left{{root}};
  int layer = 0, nodes_left_in_layer = 1, nodes_in_next_layer = 0;
  std::cout << "Layer 0:\n";
  while (!nodes_left.empty()) {
    TreeNode* node = nodes_left.front();
    std::cout << node->id << " ";
    nodes_left.pop();
    for (auto next : node->children) {
      nodes_left.push(next);
      nodes_in_next_layer++;
    }
    nodes_left_in_layer--;
    if (!nodes_left_in_layer && !nodes_left.empty()) {
      layer++;
      nodes_left_in_layer = nodes_in_next_layer;
      nodes_in_next_layer = 0;
      std::cout << "\nLayer " << layer << ":\n";
    }
  }

  return 0;
}
