#include <bits/stdc++.h>

/**
 * This implementation assumes that in a certain group of nodes S with length of N,
 * where N > 0 there is a node with minimal id of P and maximal id of M such that
 * M >= P and (M - P) + 1 = N
 */

// number of nodes in the graph
int n = 8;

std::unordered_map<int, std::vector<int>> graph{
    {0, {{1, 2}}}, 
    {1, {{0}}},  
    {2, {{0}}}, 
    {3, {{4, 5, 6}}},
    {4, {3, 5}},   
    {5, {3, 4}}, 
    {6, {3}},   
    {7, {}},
};

// groupes of conneted nodes
std::vector<std::vector<int>> groups(n);

// already visited nodes
std::vector<bool> visited(n, false);

/**
 * @param at the current node that we are at
 */
int connected_dfs(int at, int group) {
  if (visited[at]) return at;

  visited[at] = true;
  groups[group].push_back(at);

  auto neighbours = graph[at];
  int max_connection = at;
  for (auto next : neighbours) {
    max_connection = std::max(max_connection, connected_dfs(next, group));
  }

  return max_connection;
}

void connect_groups(int at, int group) {
  if (at >= n || visited[at]) return;
  int max_connection = connected_dfs(at, group);
  connect_groups(max_connection + 1, group + 1);
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  connect_groups(0, 0);

  for (int i = 0; i < n; ++i) {
    if (groups[i].empty()) continue;
    std::cout << "Group id: " << i << " : ";
    for (const auto& id : groups[i]) {
      std::cout << id << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
