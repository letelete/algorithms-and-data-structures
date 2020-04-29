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

int a, b, c;
umap<int, int> memo;

int D(int x) {
  if (x == 1) return 1;
  if (memo.count(x)) return memo[x];
  int cnt = 2;
  for (int i = 2; i <= sqrt(x); ++i) {
    if (x % i != 0) continue;
    cnt += (i * i != x) ? 2 : 1;
  }
  memo[x] = cnt;
  return cnt;
}

int main() {
  fastIO;
  std::cin >> a >> b >> c;

  i64 cnt = 0;
  for (int ai = 1; ai <= a; ++ai) {
    for (int bi = 1; bi <= b; ++bi) {
      for (int ci = 1; ci <= c; ++ci) {
        cnt += D(ai * bi * ci);
      }
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
