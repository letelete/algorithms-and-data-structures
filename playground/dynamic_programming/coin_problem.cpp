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

int main() {
  fastIO;

  int n, price, min_element = INT_MAX;
  std::cin >> n >> price;
  vint coins(n);
  for (auto& x : coins) {
    std::cin >> x;
    min_element = std::min(x, min_element);
  }

  vint dp(price + 1, 0);
  vint used(price + 1, 0);

  for (int i = min_element; i <= price; ++i) {
    dp[i] = INT_MAX;
    for (const auto& c : coins) {
      if (i - c < 0) continue;
      if (dp[i - c] + 1 < dp[i]) {
        used[i] = c;
        dp[i] = dp[i - c] + 1;
      }
    }
  }

  std::cout << "Min coins: " << dp[price] << "\nUsed coins: ";
  while (price > 0) {
    std::cout << used[price] << " ";
    price -= used[price];
  }
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
