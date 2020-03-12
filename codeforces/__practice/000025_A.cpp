
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

struct data {
  int count = 0, last_index = -1;
  void new_spot(int index) {
    ++count;
    last_index = index;
  }
};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n, x;
  std::cin >> n;

  data odd, even;

  for (int i = 0; i < n; ++i) {
    std::cin >> x;
    (x % 2 != 0 ? odd : even).new_spot(i);
  };

  int index = (odd.count > even.count ? even : odd).last_index + 1;
  std::cout << index << "\n";

  return 0;
}
