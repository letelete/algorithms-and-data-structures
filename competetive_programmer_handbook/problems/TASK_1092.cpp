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

i64 F(i64 n) {
  i64 b = n + 1;
  (n % 2 == 0 ? n : b) /= 2;
  return n * b;
}

int main() {
  fastIO;

  int n;
  std::cin >> n;

  i64 sum = F(n);
  i64 half = sum / 2;
  std::bitset<1000001> nums;

  if (sum % 2 != 0) {
    std::cout << "NO\n";
    return 0;
  }

  for (i64 i = n; half > 0; --i) {
    if ((i64)half - i < 0) continue;
    half -= i;
    nums[i] = 1;
  }

  i64 set_one_size = nums.count();

  std::cout << "YES\n";

  std::cout << set_one_size << "\n";
  for (int i = 1; i <= n; ++i) {
    if (nums[i]) std::cout << i << (i == n ? "\n" : " ");
  }

  std::cout << (n - set_one_size) << "\n";
  for (int i = 1; i <= n; ++i) {
    if (!nums[i]) std::cout << i << " ";
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
