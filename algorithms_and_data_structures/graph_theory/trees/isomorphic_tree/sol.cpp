/** ----------------------------
 * My CP templates
 * Not related to a solution beneath.
 */
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

/** ----------------------------
 * Actual solution
 */

/**
 * A graph structure to make the graph declaration easier
 * @param {repr} stands for graph representation with use of the adjacency list,
 * where ids are in range of (0..n)
 */
struct Graph {
  v<vint> repr;

  void create(int n) { repr = v<vint>(n); }

  void add_undirected_edge(int from, int to) {
    repr[from].push_back(to);
    repr[to].push_back(from);
  }
};

/**
 * A tree node with pointers to its children and the parent (if exists).
 * @param {id} stands for particular vertexes' values.
 */
struct TreeNode {
  int id;
  TreeNode* parent;
  v<TreeNode*> children;
};

/**
 * Returns ids of nodes which are the center of a given tree
 */
vint tree_centers(v<vint> tree) {
  int n = tree.size();
  vint degree(n);
  vint leaves;
  for (int i = 0; i < n; ++i) {
    degree[i] = tree[i].size();
    if (degree[i] <= 1) {
      leaves.push_back(i);
      degree[i] = 0;
    }
  }
  int count = leaves.size();
  while (count < n) {
    vint new_leaves;
    for (auto& node : leaves) {
      for (auto& neighbour : tree[node]) {
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

/**
 * Constructs an actual tree from the given node treating it as an independent
 * root of a tree.
 */
TreeNode* build_tree(v<vint> tree, TreeNode* node) {
  for (auto& child_id : tree[node->id]) {
    if (node->parent != nullptr && node->parent->id == child_id) {
      continue;
    }
    TreeNode* child = new TreeNode{child_id, node};
    node->children.push_back(child);
    build_tree(tree, child);
  }
  return node;
}

/**
 * Initializes the {build_tree} method with the real root of a tree.
 */
TreeNode* root_tree(v<vint> tree, int root_id) {
  TreeNode* root = new TreeNode{root_id};
  return build_tree(tree, root);
}

/**
 * Encodes the tree by given root with AHU technique.
 */
str encode(TreeNode* root) {
  if (node->children.empty()) return "()";
  v<str> codes;
  for (auto& child : node->children) {
    codes.push_back(encode(child));
  }
  std::sort(codes.begin(), codes.end());
  std::stringstream ss;
  for (const str& s : codes) ss << s;
  return '(' + ss.str() + ')';
}

bool trees_are_isomorphic(v<vint> tree1, v<vint> tree2) {
  vint tree1_centers = tree_centers(tree1);
  vint tree2_centers = tree_centers(tree2);

  TreeNode* tree1_root = root_tree(tree1, tree1_centers.front());
  str tree1_encoded = encode(tree1_root);
  for (auto tree2_center : tree2_centers) {
    TreeNode* tree2_root = root_tree(tree2, tree2_center);
    str tree2_encoded = encode(tree2_root);
    if (tree2_encoded == tree1_encoded) return true;
  }
  return false;
}

void solve_iso_problem(v<vint> tree1, v<vint> tree2) {
  std::cout << (trees_are_isomorphic(tree1, tree2) ? "YES" : "NO") << "\n";
}

/** ----------------------------
 * Generating graphs, calling the solution function.
 * Nothing fun to check here.
 */
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  Graph iso_tree1, iso_tree2;
  iso_tree1.create(6);
  iso_tree2.create(6);

  iso_tree1.add_undirected_edge(0, 1);
  iso_tree1.add_undirected_edge(1, 2);
  iso_tree1.add_undirected_edge(1, 4);
  iso_tree1.add_undirected_edge(4, 3);
  iso_tree1.add_undirected_edge(3, 5);

  iso_tree2.add_undirected_edge(5, 4);
  iso_tree2.add_undirected_edge(4, 3);
  iso_tree2.add_undirected_edge(4, 2);
  iso_tree2.add_undirected_edge(2, 1);
  iso_tree2.add_undirected_edge(1, 0);

  std::cout << "SHOULD SAY YES\n";
  solve_iso_problem(iso_tree1.repr, iso_tree2.repr);

  Graph not_iso_tree1, not_iso_tree2;
  not_iso_tree1.create(6);
  not_iso_tree2.create(6);

  not_iso_tree1.add_undirected_edge(0, 1);
  not_iso_tree1.add_undirected_edge(1, 2);
  not_iso_tree1.add_undirected_edge(2, 3);
  not_iso_tree1.add_undirected_edge(2, 4);
  not_iso_tree1.add_undirected_edge(2, 5);

  not_iso_tree2.add_undirected_edge(3, 4);
  not_iso_tree2.add_undirected_edge(4, 5);
  not_iso_tree2.add_undirected_edge(4, 1);
  not_iso_tree2.add_undirected_edge(1, 0);
  not_iso_tree2.add_undirected_edge(1, 2);

  std::cout << "SHOULD SAY NO\n";
  solve_iso_problem(not_iso_tree1.repr, not_iso_tree2.repr);

  return 0;
}
