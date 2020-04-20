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

const char DWARF = 'G';
const char CANDY = 'S';

int main() {
  fastIO;

  int n, m;
  std::cin >> n >> m;
  v<str> grid(n);
  uset<int> distances;
  for (auto& x : grid) {
    int candy = -1, dwarf = -1;
    std::cin >> x;
    for (int i = 0; i < x.length(); ++i) {
      if (x[i] == DWARF) dwarf = i;
      else if (x[i] == CANDY) candy = i;
    }
    int distance = candy - dwarf;
    if (distance < 0) {
      std::cout << "-1\n";
      return 0;
    }
    distances.insert(distance);
  }

  std::cout << distances.size() << "\n";

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
