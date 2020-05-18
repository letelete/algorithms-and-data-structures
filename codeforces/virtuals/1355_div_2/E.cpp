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

i64 N, A, R, M;
v<i64> h;
v<i64> pref;

i64 calc_price(i64 at) {
  auto free_range = std::equal_range(h.begin(), h.end(), at);
  i64 lo = free_range.first - h.begin() - 1, hi = free_range.second - h.begin();
  i64 lack = lo < 0 ? 0 : ((lo + 1) * at) - pref[lo];
  i64 excess = (pref.back() - pref[hi - 1]) - ((h.size() - hi) * at);
  i64 case1 = (A * lack) + (R * excess);
  i64 case2 = (excess <= lack) ? ((M * excess) + ((lack - excess) * A))
                               : ((M * lack) + ((excess - lack) * R));
  return std::min(case1, case2);
}

i64 lowest_price(i64 lo, i64 hi, i64 min_price = -1) {
  if (lo > hi) return min_price;
  i64 lo_mid = lo + ((hi - lo) / 3);
  i64 hi_mid = hi - ((hi - lo) / 3);
  i64 lo_mid_price = calc_price(lo_mid);
  i64 hi_mid_price = calc_price(hi_mid);
  if (min_price == -1) min_price = std::min(lo_mid_price, hi_mid_price);
  return (lo_mid_price < hi_mid_price)
             ? lowest_price(lo, hi_mid - 1, std::min(lo_mid_price, min_price))
             : lowest_price(lo_mid + 1, hi, std::min(hi_mid_price, min_price));
}

int main() {
  fastIO;

  std::cin >> N >> A >> R >> M;
  pref = h = v<i64>(N);
  for (auto& x : h) std::cin >> x;
  std::sort(h.begin(), h.end());

  std::partial_sum(h.begin(), h.end(), pref.begin());

  std::cout << lowest_price(h.front(), h.back()) << "\n";

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
