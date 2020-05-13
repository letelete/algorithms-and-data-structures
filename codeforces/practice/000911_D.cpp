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

template <typename T>
T accumulate(const std::vector<T>& vec, int start_from = 0) {
  T sum = std::accumulate(vec.begin(), vec.end(), start_from);
  return sum;
}

typedef long long int i64;
typedef unsigned long long ui64;

typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<char> vchar;
typedef std::vector<std::string> vstr;
typedef std::pair<int, int> pint;

i64 merge(vint& arr, int l, int mid, int r) {
  i64 inv = 0;
  vint aux;
  int lo = l, hi = mid + 1;
  while ((lo <= mid) && (hi <= r)) {
    if (arr[lo] <= arr[hi]) {
      aux.push_back(arr[lo++]);
    } else {
      inv += (mid + 1) - lo;
      aux.push_back(arr[hi++]);
    }
  }
  while (lo <= mid) aux.push_back(arr[lo++]);
  while (hi <= r) aux.push_back(arr[hi++]);
  for (int i = l, k = 0; i <= r; ++i, ++k) arr[i] = aux[k];
  return inv;
}

i64 merge_sort(vint& arr, int l, int r) {
  if (l >= r) return 0;
  int mid = l + ((r - l) / 2);
  i64 inv = 0;
  inv += merge_sort(arr, l, mid);
  inv += merge_sort(arr, mid + 1, r);
  inv += merge(arr, l, mid, r);
  return inv;
}

i64 calc_inv(const vint& arr) {
  vint copy = arr;
  return merge_sort(copy, 0, copy.size() - 1);
}

int count_swaps(int l, int r) {
  int len = (r - l) + 1;
  return ((len % 2 == 0) ? (len / 2) : ((len - 1) / 2));
}

int main() {
  fastIO;

  int n, q;
  std::cin >> n;
  vint num(n);
  for (auto& x : num) std::cin >> x;
  std::cin >> q;

  i64 inv = calc_inv(num);
  bool inv_even = inv % 2 == 0;

  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l--;
    r--;
    inv_even = (count_swaps(l, r) % 2 != 0 ? !inv_even : inv_even);
    std::cout << (inv_even ? "even" : "odd") << "\n";
  }

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
