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

const char SHIFT = 'S';

umap<char, v<pint>> keys;
umap<char, double> closest_path;
v<vchar> grid;

int n, m, x, queries, shifts = 0;
str text;
i64 count = 0;

double distance(int c1, int r1, int c2, int r2) {
  int p1 = abs(c1 - c2);
  int p2 = abs(r1 - r2);
  if (!p1) return (double)p2;
  if (!p2) return (double)p1;
  return std::sqrt((p1 * p1) + (p2 * p2));
}

double calc_dist(char c) {
  double diff = INT_MAX;

  for (auto& x : keys[c]) {
    for (auto& s : keys[SHIFT]) {
      double d = distance(s.first, s.second, x.first, x.second);
      diff = std::min(diff, d);
    }
  }

  return diff;
}

int main() {
  fastIO;

  std::cin >> n >> m >> x;

  grid = v<vchar>(n, vchar(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      std::cin >> c;
      shifts += (c == SHIFT);
      keys[c].push_back(std::make_pair(i, j));
      grid[i][j] = c;
    }
  }

  std::cin >> queries;
  std::cin >> text;

  for (const auto& c : text) {
    char clower = std::tolower(c);
    if ((keys.find(clower) == keys.end()) || (std::isupper(c) && !shifts)) {
      std::cout << "-1\n";
      return 0;
    }
    if (std::isupper(c)) {
      if (closest_path.find(clower) == closest_path.end()) {
        closest_path[clower] = calc_dist(clower);
      }
      if (closest_path[clower] > x) count++;
    }
  }

  std::cout << count << "\n";

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
