
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

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    v<std::set<int>> k(n);

    v<bool> used(n, false);

    int none = -1;

    for (int i = 0; i < n; ++i) {
      int m;
      std::cin >> m;
      bool found = false;
      while (m--) {
        int x;
        std::cin >> x;
        k[i].insert(x - 1);
        if (!found && !used[x - 1]) {
          used[x - 1] = true;
          found = true;
        }
      }
      if (!found && none == -1) {
        none = i;
      }
    }

    if (none != -1) {
      for (int i = 0; i < n; ++i) {
        if (!used[i] && !k[none].count(i)) {
          std::cout << "IMPROVE\n" << none + 1 << " " << i + 1 << "\n";
          break;
        }
      }
    } else {
      std::cout << "OPTIMAL\n";
    }
  }
  return 0;
}
