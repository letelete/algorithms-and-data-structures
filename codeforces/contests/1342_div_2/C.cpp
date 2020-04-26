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

  i64 t, a, b, q;

  std::cin >> t;
  while (t--) {
    std::cin >> a >> b >> q;
    while (q--) {
      i64 l, r;
      std::cin >> l >> r;
      if (r < b || a == b) {
        std::cout << "0 ";
        continue;
      }
      i64 blacklist = 0;
      for (i64 i = b; i <= r; i += b) {
        if (i < l) continue;
        if (((i % a) % b) == ((i % b) % a)) {
          blacklist++;
        }
      }
      i64 ans = (r - b) + 1;
      if (l >= b) ans = (r - l) + 1;
      ans -= (b * blacklist);
      std::cout << (ans < 0 ? 0 : ans) << " ";
    }
    std::cout << "\n";
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
