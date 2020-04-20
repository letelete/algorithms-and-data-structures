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

int n, m, xc, yc, k;
i64 cnt = 0;

bool valid(i64 x, i64 y, i64 q) {
  i64 resx = xc + (x * q), resy = yc + (y * q);
  return !((resx < 1 || resx > n) || (resy < 1 || resy > m));
}

int main() {
  fastIO;

  std::cin >> n >> m >> xc >> yc >> k;

  while (k--) {
    i64 x, y;
    int lo = 0, hi = std::max(n, m);
    std::cin >> x >> y;
    while (hi != lo) {
      int mid = lo + (((hi - lo) + 1) / 2);
      if (valid(x, y, mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    cnt += lo;
    xc += (x * lo);
    yc += (y * lo);
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
