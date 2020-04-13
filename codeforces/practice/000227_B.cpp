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

umap<int, int> el;

pint solve(int next) {
  int n = el.size();
  pint ans;
  if (el.find(next) == el.end()) return pint{n, n};
  ans.first = el[next] + 1;
  ans.second = n - el[next];
  return ans;
}

int main() {
  fastIO;

  int n, m;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int next;
    std::cin >> next;
    el[next] = i;
  }

  std::cin >> m;
  std::pair<i64, i64> ans{0, 0};
  while (m--) {
    int next;
    std::cin >> next;
    auto nextans = solve(next);
    ans.first += nextans.first;
    ans.second += nextans.second;
  }
  std::cout << ans.first << " " << ans.second << "\n";

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
