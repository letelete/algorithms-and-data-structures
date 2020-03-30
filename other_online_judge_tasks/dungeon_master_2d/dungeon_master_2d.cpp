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

#define START 'S'
#define EXIT 'E'
#define ROCK '#'
#define PATH '.'

#define COLORS_YELLOW "\e[93m"
#define COLORS_NORMAL "\e[39m"
#define COLORS_RED "\e[31m"
#define COLORS_GREEN "\e[32m"

int n, m;

v<v<char>> dungeon;
v<v<bool>> visited;
std::queue<pint> nodes;
std::map<pint, pint> relations;

pint start{-1, -1}, end{-1, -1};

// north south east west
const v<pint> directions{{-1, 0}, {+1, 0}, {0, +1}, {0, -1}};

int move_count = 0;
int nodes_left_in_layer = 1;
int nodes_in_next_layer = 0;

void queue_neighbours(pint node) {
  for (auto direction : directions) {
    int x = node.first + direction.first;
    int y = node.second + direction.second;
    pint next{x, y};

    if (next.first < 0 || next.second < 0) continue;
    if (next.first >= n || next.second >= m) continue;

    if (visited[next.first][next.second]) continue;
    if (dungeon[next.first][next.second] == ROCK) continue;

    visited[next.first][next.second] = true;
    nodes.push(next);
    if (relations.find(next) == relations.end()) relations[next] = node;
    ++nodes_in_next_layer;
  }
}

int bfs() {
  nodes.push(start);
  visited[start.first][start.second] = true;

  while (!nodes.empty()) {
    pint node = nodes.front();
    nodes.pop();
    queue_neighbours(node);
    if (node == end) return move_count;
    --nodes_left_in_layer;
    if (!nodes_left_in_layer) {
      nodes_left_in_layer = nodes_in_next_layer;
      nodes_in_next_layer = 0;
      ++move_count;
    }
  }

  return -1;
}

v<v<bool>> generate_path() {
  v<v<bool>> grid(n, v<bool>(m, false));
  pint cur = end;
  grid[cur.first][cur.second] = true;
  while (cur != start) {
    cur = relations[cur];
    grid[cur.first][cur.second] = true;
  }
  return grid;
}

void solve() {
  int steps = bfs();

  if (steps == -1) {
    std::cout << COLORS_RED << "You can't exit the dungeon :(" << COLORS_NORMAL
              << "\n";
    return;
  }

  auto exit_path = generate_path();
  std::cout << COLORS_GREEN << "You can exit the dungeon with " << steps
            << " steps :)" << COLORS_NORMAL << "\n\n--The Shortest Path --\n";

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      bool is_ceil_a_path = exit_path[i][j];
      char ceil = dungeon[i][j];
      std::cout << (is_ceil_a_path ? COLORS_YELLOW : COLORS_NORMAL);
      std::cout << "[" << ceil << "]";
    }
    std::cout << "\n";
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> n >> m;
  dungeon = v<v<char>>(n, v<char>(m));
  visited = v<v<bool>>(n, v<bool>(m, false));

  for (int j = 0; j < n; ++j) {
    str raw;
    std::cin >> raw;
    for (int i = 0; i < m; ++i) {
      dungeon[j][i] = raw[i];
      if (dungeon[j][i] == START) start = pint{j, i};
      if (dungeon[j][i] == EXIT) end = pint{j, i};
    }
  }

  solve();

  return 0;
}
