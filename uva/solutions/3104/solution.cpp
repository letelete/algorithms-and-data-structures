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

const char SINK = '@';
const char EMPTY = '.';
const char SHIP = 'x';

// north east south west
const vint dv{{+1, 0, -1, 0}};
const vint dh{{0, +1, 0, -1}};

v<v<char>> board;
v<v<bool>> visited;

int n;
int count_ships;

void dfs(int x, int y) {
  if (x < 0 || y < 0) return;
  if (x >= board.size() || y >= board.size()) return;
  if (board[x][y] == EMPTY) return;
  if (visited[x][y]) return;

  visited[x][y] = true;
  for (int i = 0; i < dv.size(); ++i) {
    dfs(x + dv[i], y + dh[i]);
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int t;
  std::cin >> t;
  for (int c = 0; c < t; ++c) {
    std::cin >> n;

    board = v<v<char>>(n, v<char>(n));
    visited = v<v<bool>>(n, v<bool>(n));
    count_ships = 0;

    for (auto &x : board) {
      for (auto &y : x) std::cin >> y;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == SHIP && !visited[i][j]) {
          dfs(i, j);
          ++count_ships;
        }
      }
    }

    std::cout << "Case " << (c + 1) << ": " << count_ships << "\n";
  }
  return 0;
}
