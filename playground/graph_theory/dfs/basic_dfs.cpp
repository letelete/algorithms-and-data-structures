#include <bits/stdc++.h>

// number of nodes in the graph
int n = 6;

// adjacency list representing graph
// key: node id
// value: the destination node id
std::unordered_map<int, std::vector<int>> graph{
    {0, {{1, 2, 3}}},
    {1, {{2, 4}}},
    {2, {{3, 4, 5}}},
    {3, {{5}}},
    {4, {}},
    {5, {}},
};

// already visited nodes
std::vector<bool> visited(n, false);

/**
 * @param at the current node that we are at
 */
void dfs(int at) {
  if (visited[at]) return;
  visited[at] = true;

  auto neighbours = graph[at];
  for (auto next : neighbours) {
    dfs(next);
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  // start DFS at node zero
  int start_node = 0;
  dfs(start_node);

  return 0;
}
