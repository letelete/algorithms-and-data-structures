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

vint stalls;
int cows;

bool is_limit_valid(int limit) {
  int used = 1;
  int prev = stalls[0];
  for (int i = 1; i < stalls.size(); ++i) {
    if (stalls[i] - prev >= limit) {
      ++used;
      prev = stalls[i];
    }
    if (used == cows) return true;
  }
  return false;
}

int largest_min_gap() {
  int lo = 0;
  int hi = stalls.back() - stalls.front();

  while (hi - lo > 1) {
    int limit = lo + ((hi - lo) / 2);
    bool limit_ok = is_limit_valid(limit);
    (limit_ok ? lo : hi) = limit;
  }

  return lo;
}

int main() {
  fastIO;

  int t, n;

  std::cin >> t;
  while (t--) {
    std::cin >> n >> cows;
    stalls = vint(n);
    for (int& x : stalls) std::cin >> x;

    std::sort(stalls.begin(), stalls.end());

    std::cout << largest_min_gap() << "\n";
  }

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
