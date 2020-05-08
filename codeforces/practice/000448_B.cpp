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

enum { remove_only = 0, swap_only = 1, both = 2, cant_solve = 3 };

vstr answer{{"automaton", "array", "both", "need tree"}};

str solve(const str& a, const str& b) {
  unsigned occurs_to_find = b.length();
  umap<char, int> occurs;

  if (a.length() < b.length()) return answer[cant_solve];
  if (a.find(b) != str::npos) return answer[remove_only];

  unsigned order_i = 0;
  for (unsigned i = 0; i < a.length(); ++i) {
    if (b[order_i] == a[i]) ++order_i;
    if (order_i == b.length()) return answer[remove_only];
  }

  for (const auto& x : b) ++occurs[x];

  for (const auto& x : a) {
    if (occurs.count(x) && occurs[x]) {
      --occurs[x];
      --occurs_to_find;
    }
    if (!occurs_to_find) break;
  }

  if (!occurs_to_find) {
    return (a.length() == b.length()) ? answer[swap_only] : answer[both];
  }

  return answer[cant_solve];
}

int main() {
  fastIO;

  str from, to;

  std::cin >> from >> to;
  std::cout << solve(from, to) << "\n";

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
