
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

const int mid = 3;
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  for (int i = 1; i <= 5; ++i) {
    for (int j = 1; j <= 5; ++j) {
      int x;
      std::cin >> x;
      if (x) {
        std::cout << (abs(mid - i) + abs(mid - j)) << "\n";
        return 0;
      }
    }
  }

  return 0;
}
