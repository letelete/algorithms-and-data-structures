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

template <typename T>
T accumulate(const std::vector<T>& vec, int start_from = 0) {
  T sum = std::accumulate(vec.begin(), vec.end(), start_from);
  return sum;
}

typedef long long int i64;
typedef unsigned long long ui64;

typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<char> vchar;
typedef std::vector<std::string> vstr;
typedef std::pair<int, int> pint;

int main() {
  fastIO;

  const int n = (int)1e6 + 80;
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  i64 cnt = 0;
  v<i64> sum(n, 0);
  for (int i = a; i <= b; ++i) {
    ++sum[i + b];
    --sum[i + c + 1];
  }
  std::partial_sum(sum.begin(), sum.end(), sum.begin());
  std::partial_sum(sum.begin(), sum.end(), sum.begin());
  for (int i = c; i <= d; ++i) {
    cnt += sum[n - 1] - sum[i];
  }
  std::cout << cnt << "\n";
  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
