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

struct box {
  int left = 0;
  int worth = 0;
};

bool compare(const box& a, const box& b) {
  if (a.worth == b.worth) return a.left > b.left;
  return a.worth > b.worth;
}

int main() {
  fastIO;

  int n, m;
  std::cin >> m >> n;
  v<box> boxes(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> boxes[i].left >> boxes[i].worth;
  }

  std::sort(boxes.begin(), boxes.end(), compare);

  i64 cost = 0;
  for (box& b : boxes) {
    m -= b.left;
    if (m < 0) b.left += m;
    cost += b.left * b.worth;
    if (m < 0) break;
  }

  std::cout << cost << "\n";

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
