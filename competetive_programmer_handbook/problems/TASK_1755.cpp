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

  str in;
  std::cin >> in;

  umap<char, int> c;

  for (const auto& x : in) c[x]++;

  int odd = 0;
  char odd_ch;
  for (const auto& x : c) {
    if (x.second % 2 == 0) continue;
    odd++;
    odd_ch = x.first;
  }

  std::deque<char> otp;

  if (odd > 1) {
    std::cout << "NO SOLUTION\n";
    return 0;
  }

  if (odd) {
    c[odd_ch]--;
    otp.push_back(odd_ch);
  }

  bool r = true;
  for (auto& x : c) {
    if (x.first == odd_ch) continue;
    while (x.second--) {
      (r) ? otp.push_front(x.first) : otp.push_back(x.first);
      r = !r;
    }
  }

  while (c[odd_ch]--) {
    (r) ? otp.push_front(odd_ch) : otp.push_back(odd_ch);
    r = !r;
  }

  while (!otp.empty()) {
    std::cout << otp.front();
    otp.pop_front();
  }

  std::cout << "\n";

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
