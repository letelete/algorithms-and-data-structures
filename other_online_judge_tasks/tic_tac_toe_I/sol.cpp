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

vstr grid;

bool win(char c) {
  for (int i = 0; i < 3; i++) {
    int v = 0, h = 0;
    for (int j = 0; j < 3; ++j) {
      h += grid[i][j] == c;
      v += grid[j][i] == c;
    }
    if (v == 3 || h == 3) return true;
  }
  return false;
}

int main() {
  fastIO;

  int t;
  std::cin >> t;
  while (t--) {
    grid = vstr(3);
    int x = 0, o = 0;
    for (int i = 0; i < 3; ++i) {
      std::cin >> grid[i];
      for (const auto& c : grid[i]) {
        if (c == '.') continue;
        ((c == 'X') ? x : o)++;
      }
    }

    bool xwin = win('X');
    bool owin = win('O');

    if (xwin && owin) {
      std::cout << "no\n";
      continue;
    }

    if (xwin && x - 1 == o) {
      std::cout << "yes\n";
      continue;
    }

    if (owin && x == o) {
      std::cout << "yes\n";
      continue;
    }

    if ((!xwin && !owin) && ((x - 1 == o) || (x == o))) {
      std::cout << "yes\n";
      continue;

      std::cout << "no\n";
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
