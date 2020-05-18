#include <bits/stdc++.h>

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

int mult(i64 a) {
  int max = INT_MIN, min = INT_MAX;
  while (a && max && min) {
    int num = a % 10;
    a /= 10;
    min = std::min(min, num);
    max = std::max(max, num);
  }
  return min * max;
}

int main() {
  fastIO;
  int t;
  std::cin >> t;
  while (t--) {
    i64 a, k;
    std::cin >> a >> k;
    k--;
    while (k--) {
      int m = mult(a);
      if (!m) break;
      a += m;
    }
    std::cout << a << "\n";
  }

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
