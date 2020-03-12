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

const int MAXN = 10e5;

int n;

v<i64> sums(MAXN + 1, 0);
v<i64> dp(MAXN + 1, 0);

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> n;

  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    sums[x] += x;
  }

  for (int i = 1; i <= MAXN; ++i) {
    i64 take = sums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
    i64 do_nothing = dp[i - 1];
    dp[i] = std::max(take, do_nothing);
  }

  std::cout << dp[MAXN] << "\n";

  return 0;
}
