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

const double PI = 3.14159265359;
const int LIMIT = 10e4;

int main() {
  fastIO;

  double d, h, vv, e;
  std::cin >> d >> h >> vv >> e;
  double r = (d / 2.0);
  double res = -((PI * r * r * h) / (PI * r * r * e - vv));
  if (res >= 0 && res <= LIMIT) {
    std::cout << "YES\n";
    std::cout << std::fixed << std::setprecision(12) << res << endl;
  } else {
    std::cout << "NO\n";
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
