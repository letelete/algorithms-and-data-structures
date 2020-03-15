
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

  int groups = 1;

  int n, m;
  std::cin >> n;
  int last = -1;
  while (n--) {
    std::cin >> m;
    groups += last != -1 && last != m;
    last = m;
  }

  std::cout << groups << "\n";
  return 0;
}
