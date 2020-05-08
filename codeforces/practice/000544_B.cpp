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

const char SEA = 'S';
const char ISLAND = 'L';

int n, k;

v<vchar> grid;

bool its_impossible() {
  int field = n * n;
  return !((field % 2 == 0) ? (field / 2) >= k : ((field / 2) + 1) >= k);
}

void fill_grid() {
  for (int i = 0; i < n; ++i) {
    for (int j = (i % 2 != 0); j < n; j += 2) {
      if (!k) return;
      grid[i][j] = ISLAND;
      --k;
    }
  }
}

int main() {
  fastIO;

  std::cin >> n >> k;
  grid = v<vchar>(n, vchar(n, SEA));

  if (its_impossible()) {
    std::cout << "NO\n";
    return 0;
  }

  fill_grid();

  std::cout << "YES\n";

  for (const auto& x : grid) {
    for (const auto& y : x) std::cout << y;
    std::cout << "\n";
  }

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
