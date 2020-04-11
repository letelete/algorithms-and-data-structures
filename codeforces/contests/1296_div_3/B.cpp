#include <bits/stdc++.h>
typedef long long int i64;
typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<std::string> vstr;
typedef std::vector<char> vchar;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;

int t;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  std::cin >> t;
  while (t--) {
    int s;
    std::cin >> s;
    int total = (s / 0.9);
    std::cout << total << "\n";
  }

  return 0;
}