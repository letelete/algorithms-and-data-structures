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

int get_lo(vint& arr, int val) {
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int mid = l + ((r - l + 1) / 2);
    if (arr[mid] >= val) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return (r < 0 ? -1 : r);
}

int get_hi(vint& arr, int val) {
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int mid = l + ((r - l) / 2);
    if (arr[mid] <= val) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return (l >= arr.size() ? -1 : l);
}

int main() {
  fastIO;

  int n, m;
  std::cin >> n;

  vint l(n);
  for (int& x : l) std::cin >> x;

  std::cin >> m;
  while (m--) {
    int h;
    std::cin >> h;

    int lo = get_lo(l, h);
    int hi = get_hi(l, h);

    std::cout << (lo == -1 ? "X" : std::to_string(l[lo]));
    std::cout << " ";
    std::cout << (hi == -1 ? "X" : std::to_string(l[hi]));
    std::cout << "\n";
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
