
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

  int n;
  std::cin >> n;

  v<i64> s(n);
  for (auto& x : s) std::cin >> x;
  std::sort(s.begin(), s.end());

  v<i64>::iterator it = std::upper_bound(s.begin(), s.end(), s.front());
  int left = it - s.begin();
  it = std::lower_bound(s.begin(), s.end(), s.back());
  int right = it - s.begin();
  int ans = right - left;
  std::cout << (ans < 0 ? 0 : ans) << "\n";

  return 0;
}
