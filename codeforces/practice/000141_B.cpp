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

int get_block(double a, double x, double y) {
  if (std::fmod(y, a) == 0 || y == 0) return -1;
  int block = (y + (a - std::fmod(y, a))) / a;
  int doubles = (block - 1) / 2;
  bool is_double = (y > a) && (block % 2 != 0);

  bool collision_on_single = (x <= -(a / 2)) || (x >= (a / 2));
  bool collision_on_double = (x == 0) || (x <= -a) || (x >= a);

  if (!is_double && collision_on_single) return -1;
  if (is_double && collision_on_double) return -1;

  int right = block + doubles;
  if (!is_double) return right;
  return (x > 0) ? right : (right - 1);
}

int main() {
  fastIO;

  double a, x, y;
  std::cin >> a >> x >> y;
  std::cout << get_block(a, x, y) << "\n";

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
