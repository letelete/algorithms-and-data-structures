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

const int MAX_N = 100;
std::bitset<MAX_N> minutes;

bool is_power_of_4() {
  if (minutes.count() != 1) return false;
  int count = 0;
  for (int i = 0; i < MAX_N; ++i) {
    if (minutes[i]) break;
    count++;
  }
  return count % 2 == 0;
}

int main() {
  fastIO;

  str binary;
  std::cin >> binary;
  minutes = std::bitset<MAX_N>(binary);
  bool time_is_power_of_4 = is_power_of_4();
  int trains = 0;
  while (minutes.count()) {
    if (time_is_power_of_4 && minutes[0]) break;
    ++trains;
    minutes >>= 2;
  }

  std::cout << trains << "\n";

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
