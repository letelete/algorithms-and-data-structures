
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

  vint tiles(4);
  for (int& x : tiles) std::cin >> x;
  str s;
  std::cin >> s;
  int total = 0;
  for (const char& c : s) {
    int cint = c - '0';
    total += tiles[cint - 1];
  }
  std::cout << total << "\n";

  return 0;
}
