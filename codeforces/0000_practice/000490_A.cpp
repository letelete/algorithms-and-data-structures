
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
  v<vint> ch(3);

  for (int i = 1; i <= n; ++i) {
    int power;
    std::cin >> power;
    ch[power - 1].push_back(i);
  }

  int total = std::min(std::min(ch[0].size(), ch[1].size()), ch[2].size());
  std::cout << total << "\n";
  for (int i = 0; i < total; ++i) {
    std::cout << ch[0][i] << " " << ch[1][i] << " " << ch[2][i] << "\n";
  }

  return 0;
}
