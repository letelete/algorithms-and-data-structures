
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

  if (n % 2 == 0) {
    std::cout << "NO\n";
    return 0;
  }

  std::unordered_set<char> diags;
  std::unordered_set<char> others;

  for (int i = 0, l = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char x;
      std::cin >> x;
      if (j == l || j == n - l - 1) {
        diags.insert(x);
      } else {
        others.insert(x);
      }
    }
    ++l;
  }

  bool differ = (*diags.begin()) != (*others.begin());
  bool one_el = diags.size() == 1 && others.size() == 1;
  std::cout << (differ && one_el ? "YES\n" : "NO\n");

  return 0;
}
