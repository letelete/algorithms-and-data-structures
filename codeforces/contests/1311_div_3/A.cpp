
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

int t, a, b;

int solve() {
  if (a == b) return 0;
  if (b > a) {
    return ((b - a) % 2 != 0) ? 1 : 2;
  }
  return ((a - b) % 2 == 0) ? 1 : 2;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  std::cin >> t;
  while (t--) {
    std::cin >> a >> b;
    std::cout << solve() << "\n";
  }
  return 0;
}
