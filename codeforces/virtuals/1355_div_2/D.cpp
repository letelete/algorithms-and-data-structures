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

int main() {
  fastIO;

  int n, s;
  std::cin >> n >> s;
  if (s < 2 * n) {
    std::cout << "NO\n";
    return 0;
  }

  int x = s - ((n - 1) * 2);
  std::cout << "YES\n";
  for (int i = 1; i < n; ++i) std::cout << "2 ";
  std::cout << x << "\n1\n";

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
