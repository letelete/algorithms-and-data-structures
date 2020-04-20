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

int main() {
  fastIO;

  int p, q, l, r;
  uset<int> time;
  std::cin >> p >> q >> l >> r;
  std::bitset<1001> a;

  for (int i = 0; i < p; ++i) {
    int x1, x2;
    std::cin >> x1 >> x2;
    for (int x = x1; x <= x2; ++x) a[x] = 1;
  }
  uset<int> t;
  for (int i = 0; i < q; ++i) {
    int x1, x2;
    std::cin >> x1 >> x2;
    for (int add = l; add <= r; ++add) {
      for (int x = x1; x <= x2; ++x) {
        if (x + add >= a.size()) break;
        if (a[x + add]) t.insert(add);
      }
    }
  }

  std::cout << t.size() << "\n";

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
