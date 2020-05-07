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
using spair = std::pair<T, T>;

typedef long long int i64;
typedef unsigned long long ui64;

typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<char> vchar;
typedef std::vector<std::string> vstr;
typedef std::pair<int, int> pint;

v<pint> coords(4);

enum intersection_type { none, line, point };

struct fx {
  double a{1};
  double b{0};
};

fx fx_of(pint from, pint to) {
  fx f;
  int divider = (to.first - from.first);
  f.a = !divider ? 0 : (double)(to.second - from.second) / (double)divider;
  f.b = (double)from.second - (double)(f.a * from.first);
  return f;
}

spair<double> intersection_point(fx f, fx g) {
  spair<double> ip;
  ip.first = (g.b - f.b) / (f.a - g.a);
  ip.second = (f.a * ip.first) + f.b;
  return ip;
}

intersection_type find_intersection_type(fx f, fx g, spair<double> ip) {
  if (f.a == g.a && f.b == g.b) return line;
  int x1 = coords[0].first, x2 = coords[1].first, y1 = coords[0].second,
      y2 = coords[2].second;
  if (ip.first >= std::min(x1, x2) && ip.first <= std::max(x1, x2) &&
      ip.second >= std::min(y1, y2) && ip.second <= std::max(y1, y2)) {
    return point;
  }
  return none;
}

int main() {
  fastIO;

  int n;
  std::cin >> n;

  std::cout << "INTERSECTING LINES OUTPUT\n";

  while (n--) {
    for (auto& x : coords) std::cin >> x.first >> x.second;
    auto f = fx_of(coords[0], coords[1]);
    auto g = fx_of(coords[2], coords[3]);
    auto point_xy = intersection_point(f, g);
    auto it = find_intersection_type(f, g, point_xy);
    if (it == point) {
      std::cout << "POINT " << std::fixed << std::setprecision(2)
                << point_xy.first << " " << point_xy.second << "\n";
    } else {
      std::cout << (it == none ? "NONE" : "LINE") << "\n";
    }
  }

  std::cout << "END OF OUTPUT\n";

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
