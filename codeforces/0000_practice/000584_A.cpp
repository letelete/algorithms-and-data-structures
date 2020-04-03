
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

str solve(int a, int b) {
  if (b == 10 && a == 1) return "-1";
  str ans(a, '0');
  ans[0] = (b == 10 ? 1 : b) + '0';
  return ans;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int a, b;
  std::cin >> a >> b;

  str ans = solve(a, b);
  std::cout << ans << "\n";

  return 0;
}
