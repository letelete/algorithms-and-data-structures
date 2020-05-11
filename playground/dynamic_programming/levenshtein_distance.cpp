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

// operations: insert, remove, modify

int main() {
  fastIO;

  str a_str = "TUESDAY";
  str b_str = "THURSDAY";

  v<vint> distance(a_str.size() + 1, vint(b_str.size() + 1));

  for (unsigned i = 0; i < distance.size(); ++i) distance[i][0] = i;
  for (unsigned i = 0; i < distance[0].size(); ++i) distance[0][i] = i;

  for (int a = 1; a < (int)distance.size(); ++a) {
    for (int b = 1; b < (int)distance[0].size(); ++b) {
      int insert = distance[a][b - 1] + 1;
      int remove = distance[a - 1][b] + 1;
      int modify_or_match =
          distance[a - 1][b - 1] + (a_str[a - 1] != b_str[b - 1]);
      distance[a][b] = std::min(std::min(insert, remove), modify_or_match);
    }
  }

  std::cout << distance[a_str.size()][b_str.size()] << "\n";

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
