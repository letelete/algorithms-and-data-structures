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

  int n, m, wire, bird;
  std::cin >> n;
  vint wires(n + 2);
  for (int i = 1; i <= n; ++i) std::cin >> wires[i];

  std::cin >> m;
  while (m--) {
    std::cin >> wire >> bird;
    wires[wire - 1] += bird - 1;
    wires[wire + 1] += wires[wire] - bird;
    wires[wire] = 0;
  }

  for (int i = 1; i <= n; ++i) std::cout << wires[i] << "\n";

  return 0;
}
