
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

  const int n = 4;
  std::unordered_set<i64> h;
  for (i64 i = 0, x; i < n; ++i) {
    std::cin >> x;
    h.insert(x);
  }

  std::cout << (n - h.size());

  return 0;
}
