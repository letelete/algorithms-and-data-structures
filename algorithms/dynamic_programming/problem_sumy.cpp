
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

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  int w, n;
  std::cin >> w >> n;

  vint a(n);
  for (int& i : a) std::cin >> i;
  v<bool> dp(w + 1, 0);
  dp[0] = true;
  umap<int, std::set<int>> used;
  for (int i = 1; i <= w; ++i) {
    for (const int& k : a) {
      if (i - k < 0 || used[i - k].count(k) || used[i].count(k)) continue;
      if (dp[i - k]) {
        dp[i] = true;
        used[i].insert(k);
      }
    }
  }

  std::cout << (dp[w] ? "YES" : "NO") << "\n";
  for (const auto& p : used[w]) {
    std::cout << p << " ";
  }

  return 0;
}
