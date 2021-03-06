
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

  i64 n, x, dist = 0;
  std::cin >> n >> x;

  while (n--) {
    char sign;
    int num;
    std::cin >> sign >> num;
    if (sign == '+') {
      x += num;
    } else if (x >= num) {
      x -= num;
    } else {
      dist++;
    }
  }

  std::cout << x << " " << dist << "\n";

  return 0;
}
