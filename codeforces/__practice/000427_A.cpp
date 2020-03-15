
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
  int status = 0, untreated = 0;
  while (n--) {
    int x;
    std::cin >> x;
    if (x > 0 && status <= 0) {
      status = x;
      continue;
    }
    untreated += (x == -1 && status <= 0);
    status += x;
  }

  std::cout << untreated << "\n";

  return 0;
}
