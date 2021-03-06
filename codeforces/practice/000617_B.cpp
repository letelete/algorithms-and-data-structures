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

const int MAXN = 100;

int main() {
  fastIO;

  int n;
  std::cin >> n;
  std::bitset<MAXN> bar;
  for (int i = 0, in; i < n; ++i) {
    std::cin >> in;
    if (in) bar[i] = 1;
  }
  if (!bar.count()) {
    std::cout << "0\n";
    return 0;
  }
  i64 cnt = 1, prev = -1;
  for (int i = 0; i < n; ++i) {
    if (bar[i]) {
      if (prev != -1) cnt *= i - prev;
      prev = i;
    }
  }
  std::cout << cnt << "\n";

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
