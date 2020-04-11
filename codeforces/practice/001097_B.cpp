#include <bits/stdc++.h>
typedef long long int i64;
template <typename T>
using v = std::vector<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<std::string> vstr;
typedef std::vector<char> vchar;
typedef std::pair<int, int> pint;

vint r;

// bool dfs_permutations(int node, int sum) {
//   if (node >= r.size()) return sum % 360 == 0;
//   int next = node + 1;
//   return dfs_permutations(next, sum + r[node]) ||
//          dfs_permutations(next, sum - r[node]);
// }

bool solve() {
  for (int mask = 0; mask < (1 << r.size()); ++mask) {
    int sum = 0;
    for (int i = 0; i < r.size(); ++i) {
      sum += (1 & (mask >> i)) ? r[i] : -r[i];
    }
    if (sum % 360 == 0) return true;
  }
  return false;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;
  r = vint(n);
  for (int &x : r) std::cin >> x;

  std::cout << (solve() ? "YES" : "NO") << "\n";

  return 0;
}
