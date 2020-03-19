
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

  v<i64> in(n);
  for (i64& x : in) std::cin >> x;

  i64 local_maxima = in[0];
  std::cout << local_maxima << " ";
  for (int i = 1; i < n; ++i) {
    i64 ith = local_maxima + in[i];
    std::cout << ith << " ";
    local_maxima = std::max(local_maxima, ith);
  }

  return 0;
}
