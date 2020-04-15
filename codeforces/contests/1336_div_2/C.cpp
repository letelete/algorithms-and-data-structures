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

int n, k;
umap<int, vint> g;
umap<int, bool> vis;
pq<int> happy;
pq<int> aux;
int leafs = 0;

umap<int, pq<int, vint, std::less<int>>> lay;

// void bfs() {
//   nodes.push(1);
//   while (!nodes.empty()) {
//     int parent = nodes.front();
//     nodes.pop();

//     if (g[parent].empty()) {
//       std::cout << "parent: " << parent << "\n";
//       happy.push(layer);
//     }
//     for (auto& child : g[parent]) {
//       nodes.push(child);
//       nodes_next++;
//     }

//     nodes_in_layer--;
//     if (!nodes_in_layer) {
//       nodes_in_layer = nodes_next;
//       if (nodes_in_layer) layer++;
//       nodes_next = 0;
//     }
//   }
// }

void dfs(int parent, int node, int layer) {
  if (vis[node]) return;
  vis[node] = true;
  int nodeshere = 0;
  if ((g[node].size() == 1 && g[node][0] == parent) || g[node].empty()) {
    leafs++;
    happy.push(layer);
  } else if (layer) {
    aux.push(layer);
  }
  for (auto& child : g[node]) {
    dfs(node, child, layer + 1);
    nodeshere++;
  }
  lay[node].push(nodeshere);
}

int main() {
  fastIO;

  std::cin >> n >> k;
  if (n == k) {
    std::cout << "0\n";
    return 0;
  }

  for (int i = 1; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  // for (auto& x : g) {
  //   std::cout << x.first << ": ";
  //   for (auto& y : x.second) std::cout << y << " ";
  //   std::cout << "\n";
  // }

  dfs(1, 1, 0);

  int cnt = 0;
  while (k--) {
    int top = aux.top();
    int gaux = top - lay[top];
    if (happy.empty()) {
      cnt += gaux;
      lay[top].pop();
      aux.pop();
    } else if (aux.empty()) {
      cnt += happy.top();
      happy.pop();
    } else if (happy.top() >= gaux) {
      cnt += happy.top();
      happy.pop();
    } else {
      cnt += gaux;
      lay[top].pop();
      aux.pop();
    }
  }

  std::cout << cnt << "\n";

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
