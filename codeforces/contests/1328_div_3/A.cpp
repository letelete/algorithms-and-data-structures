
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

i64 solve(i64 a, i64 b) {
  if (a <= b) return b - a;
  if (a % b == 0) return 0;
  return (((a / b) * b) + b) - a;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;
  while (n--) {
    i64 a, b;
    std::cin >> a >> b;

    std::cout << solve(a, b) << "\n";
  }

  return 0;
}
