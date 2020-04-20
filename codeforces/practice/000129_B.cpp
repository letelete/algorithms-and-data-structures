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

  umap<int, vint> g;
  umap<int, int> cnt;

  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
    cnt[a]++;
    cnt[b]++;
  }

  int groups = 0;

  vint leaves;

  for (auto& x : cnt) {
    if (x.second <= 1) {
      leaves.push_back(x.first);
      cnt[x.first] = 0;
    }
  }

  int leaves_cnt = leaves.size();
  while (leaves.size()) {
    vint new_leaves, maybe;
    groups++;
    for (auto& leaf : leaves) {
      for (auto node : g[leaf]) {
        cnt[node]--;
        if (cnt[node] == 1) maybe.push_back(node);
      }
      cnt[leaf] = 0;
    }
    for (auto& x : maybe) {
      if (cnt[x] == 1) new_leaves.push_back(x);
    }
    leaves_cnt += new_leaves.size();
    leaves = new_leaves;
  }

  std::cout << groups << "\n";

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
