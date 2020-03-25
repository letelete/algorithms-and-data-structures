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

  int n, m, c;
  while (std::cin >> n >> m >> c && n != 0) {
    int n_fields = n - 7;
    int m_fields = m - 7;
    int only_whites = 2;
    int starting_candidates = (n_fields * m_fields + c) / only_whites;
    std::cout << starting_candidates << "\n";
  }

  return 0;
}
