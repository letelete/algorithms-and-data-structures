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

enum state { B = 0, W = 1 };

const char BLACK = '#';
const char WHITE = '.';

int main() {
  fastIO;

  int n, m, x, y;
  std::cin >> n >> m >> x >> y;

  v<str> input(n);
  for (auto& line : input) std::cin >> line;

  v<v<vint>> dp(m + 1, v<vint>(2, vint(y + 1, 0)));
  vint black(m + 1), white(m + 1);

  for (int i = 0; i < m; ++i) {
    int b = 0, w = 0;
    for (int j = 0; j < n; ++j) (input[j][i] == WHITE ? black : white)[i + 1]++;
  }

  for (int i = 1; i <= x; ++i) {
    dp[i][B][x] = dp[i - 1][B][x] + black[i];
    dp[i][W][x] = dp[i - 1][W][x] + white[i];
  }

  for (int i = x + 1; i <= m; ++i) {
    for (int w = std::min(i, y); w > x; --w) {
      dp[i][B][w] = black[i] + dp[i - 1][B][w - 1];
      dp[i][W][w] = white[i] + dp[i - 1][W][w - 1];
    }

    dp[i][B][x] = dp[i][W][x] = INT_MAX;
    for (int aux = 1; aux <= y; ++aux) {
      dp[i][B][x] = black[i] + std::min(dp[i][B][x], dp[i - 1][W][aux]);
      dp[i][W][x] = white[i] + std::min(dp[i][W][x], dp[i - 1][B][aux]);
    }
  }

  int min_moves = INT_MAX;
  for (int i = 1; i <= y; ++i) {
    min_moves = std::min(min_moves, dp[m][B][i]);
    min_moves = std::min(min_moves, dp[m][W][i]);
  }

  std::cout << min_moves << "\n";

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
