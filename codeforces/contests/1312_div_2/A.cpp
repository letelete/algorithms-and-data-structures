
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
  int t, n, m;
  std::cin >> t;
  while (t--) {
    std::cin >> n >> m;
    std::cout << ((m >= 3 && n % m == 0) ? "YES\n" : "NO\n");
  }
  return 0;
}
