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

i64 n, k;

int main() {
  fastIO;

  std::cin >> n >> k;

  --n;
  --k;

  if (n == 0) {
    std::cout << "0\n";
    return 0;
  }
  if (n > k * (k + 1) / 2) {
    std::cout << "-1\n";
    return 0;
  }

  i64 l = 1, r = k + 1;
  while (l + 1 < r) {
    i64 mid = l + ((r - l) / 2);
    if ((k + mid) * (k - mid + 1) / 2 >= n) {
      l = mid;
    } else {
      r = mid;
    }
  }

  std::cout << (int)(k + 1 - l) << endl;

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
