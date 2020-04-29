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

int n;
pint gun;
map<pint, int> vec;

int abs_gcd(pint p) {
  p = std::make_pair(abs(p.first), abs(p.second));
  if (p.first < p.second) std::swap(p.first, p.second);
  while (p.second) {
    int c = p.first % p.second;
    p.first = p.second;
    p.second = c;
  }
  return p.first;
}

void morph_into_vector(pint& x) {
  if (x.first == gun.first) {
    x = std::make_pair(0, -1);
  } else if (x.second == gun.second) {
    x = std::make_pair(1, 0);
  } else {
    x = std::make_pair(gun.first - x.first, gun.second - x.second);
    int x_gcd = abs_gcd(x);
    x.first /= x_gcd;
    x.second /= x_gcd;
  }
}

void insert_vec(pint x) {
  morph_into_vector(x);
  pint inversion = std::make_pair(x.first * -1, x.second * -1);
  if (vec.count(x))
    vec[x]++;
  else if (vec.count(inversion))
    vec[inversion]++;
  else
    vec[x] = 1;
}

int main() {
  fastIO;
  std::cin >> n >> gun.first >> gun.second;

  while (n--) {
    pint p;
    std::cin >> p.first >> p.second;
    insert_vec(p);
  }

  std::cout << vec.size() << "\n";

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
