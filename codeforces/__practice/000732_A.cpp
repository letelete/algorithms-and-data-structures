
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

  int k, r;
  std::cin >> k >> r;

  int num = k, best = 10;

  for (int i = 1; i <= 10; ++i) {
    int curk = k * i;
    if (curk % 10 == 0 || curk == r || (curk - r) % 10 == 0) {
      if (best > i) {
        best = i;
        break;
      };
    }
  }

  std::cout << best << "\n";
}
