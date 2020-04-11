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

int count_steps(vstr& ds, int count) {
  if (ds.empty()) return count;
  const int limit = 99;
  vstr nds;
  int cur_sum = 0;
  count++;
  for (int i = 0; i < ds.size(); ++i) {
    int next = std::stoi(ds[i]);
    int final_next = (next < 10) ? next : ((next % 10) + (next / 10));
    if (cur_sum + final_next > limit) {
      nds.push_back(std::to_string(cur_sum));
      cur_sum = final_next;
    } else {
      cur_sum += final_next;
    }
  }
  if (cur_sum != 0) nds.push_back(std::to_string(cur_sum));

  if (nds.size() == 1 && std::stoi(nds[0]) <= 9) nds.clear();

  return count_steps(nds, count);
}
int solve(str& s) {
  if (s.size() <= 1 && std::stoi(s) < 10) return 0;
  vstr ds((s.size() + 1) / 2, "0");
  str next(2, '0');
  for (int i = 0, l = 0, d = 0; i < s.size(); ++i) {
    next[l++] = s[i];
    if (l >= 2 || i == s.size() - 1) {
      ds[d++] = next;
      next = str(2, '0');
      l = 0;
    }
  }

  return count_steps(ds, 0);
}

int main() {
  fastIO;

  str n;
  std::cin >> n;

  std::cout << solve(n) << "\n";

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
