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

struct Node {
  int weight;
  char letter;
  char code = '\0';
  Node* left = nullptr;
  Node* right = nullptr;
};

struct Comp {
  bool operator()(const Node* a, const Node* b) {
    if (a->weight == b->weight) return a->letter > b->letter;
    return a->weight > b->weight;
  }
};

void traverse_tree(Node* node, str code) {
  if (!node) return;
  code.push_back(node->code);
  if (node->letter)
    std::cout << node->letter << " " << code << " " << node->weight << "\n";
  traverse_tree(node->left, code);
  traverse_tree(node->right, code);
}

int main() {
  fastIO;

  str sequence = "AAAAAAAAAAAABBBDAJKHIDKSGDYUIGSDUICCD";

  umap<char, int> occurences;
  for (const auto& letter : sequence) occurences[letter]++;

  std::priority_queue<Node*, v<Node*>, Comp> nodes;
  for (const auto& x : occurences) {
    Node* node = new Node();
    node->letter = x.first;
    node->weight = x.second;
    nodes.push(node);
  }

  Node* root = nodes.top();
  nodes.pop();

  while (!nodes.empty()) {
    Node* parent = new Node();
    Node* right = root;
    Node* left = nodes.top();
    std::cout << nodes.top()->letter << " " << nodes.top()->weight << "\n";
    nodes.pop();
    right->code = '1';
    left->code = '0';
    parent->right = right;
    parent->left = left;
    parent->weight = right->weight + left->weight;
    root = parent;
  }

  traverse_tree(root, str(0, '\0'));

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
