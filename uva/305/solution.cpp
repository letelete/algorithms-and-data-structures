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

int n, m;

int calc_gcd(int a, int b) { return !b ? a : calc_gcd(b, a % b); }

i64 solve() {
  if (n == m) return 1;
  vint a, b;
  int start_a_at = std::max(n - m, m) + 1;

  for (int i = start_a_at; i <= n; ++i) a.push_back(i);
  for (int i = 2; i <= std::min(n - m, m); ++i) b.push_back(i);

  for (int i = 0; i < b.size(); ++i) {
    for (int j = 0; j < a.size(); ++j) {
      if (b[i] == 1) break;
      if (a[j] == 1) continue;

      int max_val = std::max(b[i], a[j]);
      int min_val = std::min(b[i], a[j]);
      if (max_val % min_val == 0) {
        a[j] /= min_val;
        b[i] /= min_val;
        continue;
      }

      int gcd = calc_gcd(max_val, min_val);
      if (gcd <= 1) continue;
      a[j] /= gcd;
      b[i] /= gcd;
    }
  }

  i64 am = 1, bm = 1;
  for (const auto& x : a) am *= x;
  for (const auto& x : b) bm *= x;

  return am / bm;
}

int main() {
  fastIO;

  while (std::cin >> n >> m && n != 0) {
    i64 ans = solve();
    std::cout << n << " things taken " << m << " at a time is " << ans
              << " exactly.\n";
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
