
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

  i64 n, k;
  std::cin >> n >> k;

  i64 odds = n / 2 + (n % 2 != 0);
  i64 even = n / 2;
  std::cout << (k > odds ? (k - odds) * 2 : (k * 2) - 1) << "\n";

  return 0;
}
