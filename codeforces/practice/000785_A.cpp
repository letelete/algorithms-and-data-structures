
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

  umap<str, int> polyhedrons{{"Tetrahedron", 4},
                             {"Cube", 6},
                             {"Octahedron", 8},
                             {"Dodecahedron", 12},
                             {"Icosahedron", 20}};
  int n;
  std::cin >> n;
  unsigned int sum = 0;
  while (n--) {
    str x;
    std::cin >> x;
    sum += polyhedrons[x];
  }
  std::cout << sum << "\n";

  return 0;
}
