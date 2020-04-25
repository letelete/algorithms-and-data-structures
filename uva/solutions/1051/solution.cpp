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

#define MAXN (2ll << 31) - 1

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  i64 n;
  while (std::cin >> n && n != 0) {
    i64 sqn = sqrt(n);
    std::cout << (sqn * sqn == n ? "yes" : "no") << "\n";
  }

  return 0;
}
