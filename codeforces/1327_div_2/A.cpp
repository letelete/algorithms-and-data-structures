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

bool solve(int n, int k) {
  if ((n % 2 == 0 && k % 2 == 0) || (n % 2 != 0 && k % 2 != 0)) {
    double nd = n, kd = k;
    return sqrt(nd) >= k;
  }
  return false;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int t, n, k;
  std::cin >> t;
  while (t--) {
    std::cin >> n >> k;
    std::cout << (solve(n, k) ? "YES" : "NO") << "\n";
  }
  return 0;
}
