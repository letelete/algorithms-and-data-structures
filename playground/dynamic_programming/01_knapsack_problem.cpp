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

  vint w{{5, 3, 4, 2}};
  vint p{{60, 50, 70, 30}};
  int n = 5;

  v<vint> dp(w.size() + 1, vint(n + 1, 0));
  for (int i = 1; i <= w.size(); ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - w[i - 1] >= 0) {
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
      }
    }
  }

  std::cout << dp[w.size()][n] << "\n";

  return 0;
}
