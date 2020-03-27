
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

int t, n, k;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> t;
  while (t--) {
    std::cin >> n >> k;
    str res(n, 'a');
    for (int i = n - 2; i >= 0; --i) {
      int group = n - i - 1;
      if (k <= group) {
        res[i] = res[n - k] = 'b';
        std::cout << res << "\n";
        break;
      }
      k -= group;
    }
  }

  return 0;
}
