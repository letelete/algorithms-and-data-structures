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

int n, m;

// north south east west
v<pint> drs{{-1, 0}, {+1, 0}, {0, +1}, {0, -1}};

v<v<char>> dungeon;
v<v<bool>> visited;
std::queue<pint> nodes;

pint start{-1, -1}, end{-1, -1};

void print_title(str msg) { std::cout << "-- " << msg << " --\n"; }

std::map<pint, pint> bfs() {
  nodes.push(start);
  std::map<pint, pint> path;

  while (!nodes.empty()) {
    pint node = nodes.front();
    visited[node.first][node.second] = true;
    if (node == end) return path;
    nodes.pop();

    if (dungeon[node.first][node.second] == ROCK) continue;

    for (int i = 0; i < drs.size(); ++i) {
      pint next{node.first + drs[i].first, node.second + drs[i].second};
      if (next.first < 0 || next.second < 0) continue;
      if (next.first >= n || next.second >= m) continue;

      if (!visited[next.first][next.second]) {
        nodes.push(next);
        if (path.find(next) == path.end()) path[next] = node;
      }
    }
  }

  return {};
}

struct path {
  int steps = 0;
  v<v<bool>> grid;
};

path generate_path(std::map<pint, pint> moves) {
  path p{0, v<v<bool>>(n, v<bool>(m, false))};
  pint cur = end;
  p.grid[cur.first][cur.second] = true;
  while (cur != start) {
    cur = moves[cur];
    p.grid[cur.first][cur.second] = true;
    p.steps++;
  }
  return p;
}

void solve() {
  auto moves = bfs();
  if (moves.empty()) {
    std::cout << "You can't exit the dungeon :(\n";
  } else {
    auto exit_path = generate_path(moves);
    std::cout << "You can exit the dungeon with " << exit_path.steps
              << " steps :)\n\n";
    print_title("The Shortest Path");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cout << (exit_path.grid[i][j] ? "\e[33m" : "\e[39m") << "["
                  << dungeon[i][j] << "]";
      }
      std::cout << "\n";
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> n >> m;
  dungeon = v<v<char>>(n, v<char>(m));
  visited = v<v<bool>>(n, v<bool>(m, false));

  print_title("The Dungeon");
  for (int j = 0; j < n; ++j) {
    str raw;
    std::cin >> raw;
    for (int i = 0; i < m; ++i) {
      dungeon[j][i] = raw[i];
      if (dungeon[j][i] == START) start = pint{j, i};
      if (dungeon[j][i] == EXIT) end = pint{j, i};
      std::cout << "[" << raw[i] << "]";
    }
    std::cout << "\n";
  }
  assert(start.first != -1 && start.second != -1);
  assert(end.first != -1 && end.second != -1);

  std::cout << "\n";
  solve();

  return 0;
}
