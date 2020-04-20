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

struct compare {
  bool operator()(const pair<int, double>& a, const pair<int, double>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
  }
};

int main() {
  fastIO;

  double n, t1, t2, k, x, y;
  std::cin >> n >> t1 >> t2 >> k;
  std::priority_queue<pair<int, double>, v<pair<int, double>>, compare> dwarf;
  for (double i = 1; i <= n; ++i) {
    std::cin >> x >> y;
    int max = std::max(x, y);
    int min = std::min(x, y);
    double res = ((t1 * min) - (t1 * min * k * 0.01)) + (t2 * max);
    double res2 = ((t1 * max) - (t1 * max * k * 0.01)) + (t2 * min);
    dwarf.push(std::make_pair(i, std::max(res, res2)));
  }

  while (!dwarf.empty()) {
    std::cout << std::fixed << std::setprecision(2) << dwarf.top().first << " "
              << dwarf.top().second << "\n";
    dwarf.pop();
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
