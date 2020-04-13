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

const int SIZE = 9;

v<uset<int>> bl;
v<bool> left;

v<vint> solve(v<vint> sudoku) {
  int prev;
  int pos = 0;
  for (int block = 0; block < 3; ++block) {
    for (int i = 1; i <= SIZE; ++i) {
      if (bl[block].count(i)) continue;
      if (!left[i]) continue;
      if (block == 2 && pos == SIZE - 1) {
        sudoku[pos][pos] = prev;
      } else {
        sudoku[pos][pos] = i;
        prev = i;
        left[i] = false;
        pos++;
      }
      i = SIZE;
    }
  }

  return sudoku;
}

int main() {
  fastIO;

  int t;
  std::cin >> t;
  while (t--) {
    v<vint> sudoku(SIZE, vint(SIZE));
    for (int i = 0; i < SIZE; ++i) {
      str line;
      std::cin >> line;
      for (int j = 0; j < SIZE; ++j) {
        sudoku[i][j] = line[j] - '0';
      }
    }

    left = v<bool>(SIZE + 1, true);
    left[0] = false;
    bl = v<uset<int>>(3);
    bl[0] = uset<int>({sudoku[0][0], sudoku[1][1], sudoku[2][2]});
    bl[1] = uset<int>({sudoku[3][3], sudoku[4][4], sudoku[5][5]});
    bl[2] = uset<int>({sudoku[6][6], sudoku[7][7], sudoku[8][8]});
    v<vint> ans = solve(sudoku);
    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        std::cout << ans[i][j];
      }
      std::cout << "\n";
    }
  }

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
