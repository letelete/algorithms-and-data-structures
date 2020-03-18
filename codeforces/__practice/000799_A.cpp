
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

  int n, t, k, d;
  std::cin >> n >> t >> k >> d;

  int single_o = (n / k) * t;
  if (n % k != 0) single_o += t;

  int double_o = 0;
  int double_c = 0;
  for (int i = 1; i < single_o; ++i) {
    if (i % t == 0) double_c += k;
    if (d - i < 0 && i % t == 0) double_c += k;
    if (double_c >= n) {
      std::cout << "YES\n";
      return 0;
    }
  }
  std::cout << "NO\n";
  return 0;
}
