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
  while (n--) {
    str w;
    std::cin >> w;
    int len = w.length();
    if (len > 10) {
      std::cout << w[0] << len - 2 << w[len - 1];
    } else {
      std::cout << w;
    }
    std::cout << "\n";
  }

  return 0;
}