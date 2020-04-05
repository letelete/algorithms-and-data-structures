#include <bits/stdc++.h>
#pragma GCC target("popcnt")
#define fastIO      \
  std::cin.tie(0);  \
  std::cout.tie(0); \
  std::ios::sync_with_stdio(0);
#define endl "\n"
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
typedef long long int i64;
typedef unsigned long long ui64;
typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<char> vchar;
typedef std::vector<std::string> vstr;
typedef std::pair<int, int> pint;

int main() {
  fastIO;

  i64 n, k;
  std::cin >> n >> k;

  if (n == 1) {
    std::cout << "1\n";
    return 0;
  }

  i64 l = k, r = n - 1, best = n;

  while (l <= r) {
    i64 mid = l + ((r - l) / 2);
    i64 p = mid, sum = 0;
    for (int i = 1; p; ++i) {
      sum += p;
      p = mid / std::pow(k, i);
    }
    if (sum >= n) {
      if (best >= mid) {
        best = mid;
        r = mid - 1;
      }
    } else {
      l = mid + 1;
    }
  }

  std::cout << best << "\n";

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */

/** ⚠ Common mistakes
 *
 */
