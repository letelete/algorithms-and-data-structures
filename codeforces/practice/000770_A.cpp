
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

  int n, k;
  std::cin >> n >> k;
  for (int i = 0, dist = 0; i < n; ++i) {
    std::cout << char('a' + dist++);
    if (dist >= k) dist = 0;
  }
  std::cout << "\n";

  return 0;
}
