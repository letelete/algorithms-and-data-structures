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

void solve(str a, str b) {
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());
  int maxlen = std::max(a.length(), b.length());
  vint prod(2 * maxlen, 0);
  for (int i = prod.size() - 1, j = 0; i >= prod.size() - maxlen; --i, j++) {
    if (j >= a.size() && j >= b.size()) break;
    int next = 0;
    if (j < a.size()) next += a[j] - '0';
    if (j < b.size()) next += b[j] - '0';
    prod[i] = next;
  }

  for (int i = prod.size() - 1, stay, goes; i > 0; --i) {
    stay = prod[i] <= 9 ? prod[i] : prod[i] % 10;
    goes = prod[i] / 10;
    prod[i] = stay;
    prod[i - 1] += goes;
  }

  bool read = false;
  for (int i = 0; i < prod.size(); ++i) {
    if (!read && prod[i]) read = true;
    if (read) std::cout << prod[i];
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
