
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

  int t;
  std::cin >> t;
  while (t--) {
    i64 size = 0, n, x;
    std::cin >> n;
    std::unordered_set<i64> seen;
    while (n--) {
      std::cin >> x;
      size += (seen.count(x) == 0);
      seen.insert(x);
    }
    std::cout << size << "\n";
  }

  return 0;
}
