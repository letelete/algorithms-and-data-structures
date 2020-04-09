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

int min_max(vint& stalls, int c) {
  vint gaps(stalls.size(), 0);

  int lo = INT_MAX;
  for (int i = 1; i < stalls.size(); ++i) {
    int gap = stalls[i] - stalls[i - 1];
    gaps[i] = gap;
    lo = std::min(lo, gap);
  }
  int hi = std::accumulate(gaps.begin(), gaps.end(), 0);
  while (lo < hi) {
    int limit = lo + (hi - lo) / 2;
    int gap_sum = 0;
    int used = 1;
    for (int i = 0; i < gaps.size(); ++i) {
      if (gap_sum + gaps[i] <= limit) {
        gap_sum += gaps[i];
      } else {
        used++;
        gap_sum = gaps[i];
      }
    }

    if (used <= c) {
      hi = limit;
    } else {
      lo = limit + 1;
    }
  }

  return lo;
}

int main() {
  fastIO;

  int t;
  std::cin >> t;
  while (t--) {
    int n, c;
    std::cin >> n >> c;
    vint stalls(n);
    for (int& x : stalls) std::cin >> x;

    std::sort(stalls.begin(), stalls.end());

    std::cout << min_max(stalls, c) << "\n";
  }

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
