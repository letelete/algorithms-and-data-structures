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

int biggest_power_of_2_that_is_divisor_of_x(int x) {
  int trailing_zeros = __builtin_ctz(abs(x));
  return 1 << trailing_zeros;
}

int smallest_power_of_2_that_is_not_smaller_than_x(int x) {
  if (x <= 1) return 1;
  return 1 << (32 - __builtin_clz(x - 1));
}

int main() {
  fastIO;

  int number = 16;

  std::cout << std::bitset<8>(number) << "\n";
  std::cout << "Compute the biggest power of 2 that is a divisor of x: "
            << biggest_power_of_2_that_is_divisor_of_x(number) << endl;
  std::cout << "Compute the smallest power of 2 that is not smaller than x: "
            << smallest_power_of_2_that_is_not_smaller_than_x(number) << endl;

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