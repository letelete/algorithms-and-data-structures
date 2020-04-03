
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

  str path;
  std::cin >> path;

  int r = 0, l = 0, first_r = -1, first_l = -1, last_l, last_r;
  for (int i = 1; i < n; ++i) {
    char& c = path[i];
    r += c == 'R';
    l += c == 'L';
    if (first_r == -1 && c == 'R') first_r = i;
    if (first_l == -1 && c == 'L') first_l = i;
    if (c == 'R') last_r = i;
    if (c == 'L') last_l = i;
  }

  int s, t;
  if (l >= r) {
    s = last_l;
    t = first_l - 1;
  } else {
    s = first_r;
    t = last_r + 1;
  }

  std::cout << ++s << " " << ++t << "\n";

  return 0;
}
