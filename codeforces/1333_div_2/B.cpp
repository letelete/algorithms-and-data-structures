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

int main() {
  fastIO;

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    vint a(n), b(n);
    for (int& x : a) std::cin >> x;
    for (int& x : b) std::cin >> x;
    v<bool> positive(n, false);
    v<bool> negative(n, false);
    for (int i = 1; i < n; ++i) {
      positive[i] = positive[i - 1];
      negative[i] = negative[i - 1];
      if (a[i - 1] > 0) {
        positive[i] = true;
      } else if (a[i - 1] < 0) {
        negative[i] = true;
      }
    }

    bool flag = true;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] == b[i]) continue;
      if (a[i] < b[i] && (!positive[i])) {
        flag = false;
      } else if (a[i] > b[i] && (!negative[i])) {
        flag = false;
      }
    }

    std::cout << (flag ? "YES" : "NO") << "\n";
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
