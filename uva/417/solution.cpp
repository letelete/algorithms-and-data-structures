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

struct rect {
  int id;
  double x1, y1, x2, y2;

  bool inrange(double x, double y) {
    return x >= x1 && x <= x2 && y <= y1 && y >= y2;
  }
};

v<rect> rects;

vint test(double x, double y) {
  vint res;
  for (auto& r : rects) {
    if (r.inrange(x, y)) res.push_back(r.id);
  }
  return res;
}

int main() {
  fastIO;

  char figure;
  int index = 1;
  while (std::cin >> figure && figure == 'r') {
    rect r{index++};
    std::cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
    rects.push_back(r);
  }

  for (double x, y, i = 1; std::cin >> x >> y && (x != 9999.9); ++i) {
    vint contains = test(x, y);
    for (const auto& x : contains) {
      std::cout << "Point " << i << " is contained in figure " << x << "\n";
    }
    if (contains.empty()) {
      std::cout << "Point " << i << " is not contained in any figure\n";
    }
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
