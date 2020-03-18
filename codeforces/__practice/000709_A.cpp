
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

  int n, b, d, o;
  std::cin >> n >> b >> d;

  i64 waste = 0, total = 0;
  while (n--) {
    std::cin >> o;
    if (o <= b) {
      waste += o;
      if (waste > d) {
        waste = 0;
        ++total;
      }
    }
  }

  std::cout << total << " \n";

  return 0;
}
