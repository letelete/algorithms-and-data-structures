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

int get_most_work(vint& files, int workers) {
  int lo = *std::max_element(files.begin(), files.end());
  int hi = std::accumulate(files.begin(), files.end(), 0);

  while (lo < hi) {
    int limit = lo + (hi - lo) / 2;
    int w = 1;
    int sum = 0;

    for (int i = 0; i < files.size(); ++i) {
      if (sum + files[i] <= limit) {
        sum += files[i];
      } else {
        w++;
        sum = files[i];
      }
    }

    if (w <= workers) {
      hi = limit;
    } else {
      lo = limit + 1;
    }
  }

  return lo;
}

int main() {
  fastIO;

  int n, m;
  std::cin >> n >> m;
  vint files(n);
  for (int& x : files) std::cin >> x;
  std::sort(files.begin(), files.end());
  std::cout << get_most_work(files, m) << "\n";

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
