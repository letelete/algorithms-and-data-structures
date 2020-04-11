#include <bits/stdc++.h>
typedef long long int i64;
typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<std::string> vstr;
typedef std::vector<char> vchar;
typedef std::pair<int, int> pint;
template <typename T>
using v = std::vector<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;

int n, k, x, y;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> n;
  while (n--) {
    std::cin >> k;
    int sum = 0;
    bool has_even = false, has_odd = false;
    while (k--) {
      std::cin >> x;
      y = x % 2;
      if (y) has_odd = true;
      else has_even = true;
      sum += y;
    }
    std::cout << (sum % 2 == 1 || (has_even && has_odd) ? "YES" : "NO") << "\n";
  }

  return 0;
}