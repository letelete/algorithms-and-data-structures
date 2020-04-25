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

void solve(const str& a, const str& b) {
  int maxlen = std::max(a.length(), b.length());
  vint prod(2 * maxlen, 0);

  for (int i = 0; i < maxlen; ++i) {
    if (i < a.length()) prod[i] += a[i] - '0';
    if (i < b.length()) prod[i] += b[i] - '0';
  }

  int last_significant_index = 0;
  for (int i = 0; i < prod.size(); ++i) {
    int stay = prod[i] <= 9 ? prod[i] : prod[i] % 10;
    int goes = prod[i] / 10;
    prod[i] = stay;
    prod[i + 1] += goes;
    if (stay || goes) last_significant_index = i;
  }

  bool is_leading_zero = true;
  for (int i = 0; i <= last_significant_index; ++i) {
    if (!prod[i] && is_leading_zero) continue;
    is_leading_zero = false;
    std::cout << prod[i];
  }

  std::cout << "\n";
}

int main() {
  fastIO;

  int n;
  str a, b;
  std::cin >> n;
  while (n--) {
    std::cin >> a >> b;
    solve(a, b);
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
