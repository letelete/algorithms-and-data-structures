#include <bits/stdc++.h>

int nodes = 5;
// adjacency list representing graph
std::unordered_map<char, std::vector<char>> graph{{'a', {'b', 'c'}},
                                                  {'b', {'d', 'f'}},
                                                  {'c', {'d', 'b'}},
                                                  {'d', {'f', 'g'}},
                                                  {'g', {}}};

std::map<char, char> bfs(char start_node) {
  std::queue<char> unvisited{{start_node}};
  std::unordered_set<char> visited{{start_node}};
  std::map<char, char> prev;

  while (!unvisited.empty()) {
    auto node = unvisited.front();
    unvisited.pop();
    std::vector<char> neighbors = graph[node];
    for (const auto& next : neighbors) {
      if (!visited.count(next)) {
        unvisited.push(next);
        visited.insert(next);
        prev[next] = node;
      }
    }
  }

  return prev;
}

std::vector<char> reconstruct_path(char start_node, char end_node,
                                   std::map<char, char> prev) {
  std::vector<char> path;
  for (auto at = end_node; at != '\0'; at = prev[at]) {
    path.push_back(at);
  }
  std::reverse(path.begin(), path.end());

  if (path[0] == start_node) return path;
  return std::vector<char>();
}

std::vector<char> shortest_path(char start_node, char end_node) {
  auto prev = bfs(start_node);
  return reconstruct_path(start_node, end_node, prev);
}

int main() {
  auto path = shortest_path('a', 'g');
  for (const auto& p : path) std::cout << p << " ";
  std::cout << "\n";
  return 0;
}