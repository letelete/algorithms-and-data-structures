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

int t, n;
str x;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  std::cin >> t;
  while (t--) {
    std::cin >> n >> x;
    str a(n, '0'), b(n, '0');
    bool increased_a = false;
    for (int i = 0; i < n; ++i) {
      if (x[i] == '1') {
        a[i] = increased_a ? '0' : '1';
        b[i] = increased_a ? '1' : '0';
        increased_a = true;
      } else if (x[i] == '2') {
        a[i] = increased_a ? '0' : '1';
        b[i] = increased_a ? '2' : '1';
      }
    }
    std::cout << a << "\n" << b << "\n";
  }
  return 0;
}