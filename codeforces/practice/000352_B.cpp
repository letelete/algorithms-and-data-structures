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

enum codes { ILLEGAL_PROG_X = -2, NOT_INIT_X = -1, NO_PROG_X = -1 };

struct num {
  int prog = NO_PROG_X;
  int last = NOT_INIT_X;
};

int main() {
  fastIO;

  map<int, num> obs;

  int n;
  std::cin >> n;

  vint nums(n);
  for (auto& x : nums) std::cin >> x;

  int legal = 0;
  for (int i = 0; i < n; ++i) {
    auto& x = obs[nums[i]];
    if (x.prog == ILLEGAL_PROG_X) continue;
    if (x.last == NOT_INIT_X) {
      x.last = i;
      legal++;
    } else if (x.prog == NO_PROG_X) {
      x.prog = i - x.last;
    } else {
      int next_prog = i - x.last;
      if (next_prog != x.prog) {
        x.prog = ILLEGAL_PROG_X;
        legal--;
      }
    }
    x.last = i;
  }

  std::cout << legal << "\n";
  for (auto& o : obs) {
    if (o.second.prog == ILLEGAL_PROG_X) continue;
    if (o.second.prog == NO_PROG_X)
      std::cout << o.first << " 0\n";
    else
      std::cout << o.first << " " << o.second.prog << "\n";
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
