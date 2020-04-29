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

int x1, y1, x2, y2, n, uncomfy = 0;
v<double> rx, ry, rr;

v<pint> dr{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
vint ddist;

void traverse(double x, double y, unsigned d_i, int steps) {
  bool safe = false;
  for (unsigned i = 0; i < rx.size(); ++i) {
    double dist = sqrt((double)std::pow(abs(x - rx[i]), 2) +
                       (double)std::pow(abs(y - ry[i]), 2));
    if (dist <= rr[i]) {
      safe = true;
      break;
    }
  }
  if (!safe) ++uncomfy;
  if (steps >= ddist[d_i]) {
    steps = 0;
    ++d_i;
    if (d_i == dr.size()) return;
  }
  int next_x = x + dr[d_i].first;
  int next_y = y + dr[d_i].second;
  if (next_x == x1 && next_y == y1) return;
  ++steps;
  traverse(next_x, next_y, d_i, steps);
}

int main() {
  fastIO;

  std::cin >> x1 >> y1 >> x2 >> y2 >> n;
  rx = ry = rr = v<double>(n);

  if (x1 > x2) std::swap(x1, x2);
  if (y1 < y2) std::swap(y1, y2);

  ddist = vint(4);
  ddist[0] = ddist[2] = abs(x2 - x1);
  ddist[1] = ddist[3] = abs(y2 - y1);

  while (n--) std::cin >> rx[n] >> ry[n] >> rr[n];

  traverse(x1, y1, 0, 0);

  std::cout << uncomfy << "\n";

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
