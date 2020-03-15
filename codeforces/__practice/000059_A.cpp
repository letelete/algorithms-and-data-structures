
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

  str word;
  std::cin >> word;
  int uppercases = 0;
  for (const char& c : word) uppercases += c == toupper(c);
  for (const char& c : word) {
    std::cout << char(uppercases > word.length() / 2 ? toupper(c) : tolower(c));
  }
  std::cout << "\n";

  return 0;
}
