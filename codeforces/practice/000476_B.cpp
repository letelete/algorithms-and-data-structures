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

int ans(double x) {
  std::cout << std::fixed << std::setprecision(12) << x << "\n";
  return 0;
}

int main() {
  fastIO;

  str a, b;
  std::cin >> a >> b;

  int p = 0, m = 0;
  for (auto& x : a) (x == '+' ? p : m)++;

  int bp = 0, bm = 0, bq = 0;
  for (auto& x : b) ((x == '?') ? bq : ((x == '+') ? bp : bm))++;

  if (bq == 0) {
    if (bp == p && bm == m) return ans(1);
    return ans(0);
  }

  int combinations = 0, valid = 0;
  for (int mask = 0; mask < (1 << bq); ++mask) {
    int tp = bp, tm = bm;
    for (int i = 0; i < bq; ++i) {
      if (1 & (mask >> i)) {
        tm++;
      } else {
        tp++;
      }
    }
    combinations++;
    valid += (tp == p && tm == m);
  }

  double res = (double)valid / (double)combinations;
  return ans(res);
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
