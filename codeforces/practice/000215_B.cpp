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

  int r1 = 0, p1 = 0, p2 = INT_MAX, n, x, A, B;
  std::cin >> n;
  while (n--) {
    std::cin >> x;
    r1 = std::max(r1, x);
  }
  std::cin >> n;
  while (n--) {
    std::cin >> x;
    p1 = std::max(p1, x);
  }
  std::cin >> n;
  while (n--) {
    std::cin >> x;
    p2 = std::min(p2, x);
  }
  std::cin >> A >> B;
  std::cout << std::fixed << std::setprecision(12)
            << sqrt(((double)B * p1 * r1 * r1) / ((double)A * p2 + B * p1))
            << "\n";

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
