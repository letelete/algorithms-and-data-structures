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

int price(char c) { return ((int)c - 'a') + 1; }

int substitution_cost(char a, char b) { return abs(price(a) - price(b)); }

int levenshtein_dist(str from, str to) {
  int from_len = (int)from.length();
  int to_len = (int)to.length();
  v<vint> dist(from_len + 1, vint(to_len + 1, 0));

  for (int i = 1; i <= from_len; ++i) dist[i][0] = price(from[i - 1]);
  for (int i = 1; i <= to_len; ++i) dist[0][i] = price(to[i - 1]);

  for (int a = 1; a <= from_len; ++a) {
    for (int b = 1; b <= to_len; ++b) {
      char &a_ch = from[a - 1], &b_ch = to[b - 1];
      int subst = dist[a - 1][b - 1] + substitution_cost(a_ch, b_ch);
      int insert = dist[a][b - 1] + price(b_ch);
      int del = dist[a - 1][b] + price(a_ch);
      dist[a][b] = std::min(std::min(subst, insert), del);
    }
  }

  return dist[from_len][to_len];
}

int main() {
  fastIO;

  str a, b;
  std::cin >> a >> b;

  std::cout << levenshtein_dist(a, b) << "\n";

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
