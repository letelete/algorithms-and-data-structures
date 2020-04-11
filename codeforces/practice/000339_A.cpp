
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

  str base;
  std::cin >> base;

  vint nums(4, 0);
  int total = 0;
  for (int i = 0; i < base.length(); i += 2) {
    int num = base[i] - '0';
    nums[num]++;
    ++total;
  }

  for (int i = 1; i < nums.size(); ++i) {
    while (nums[i]--) {
      std::cout << i << (--total > 0 ? "+" : "\n");
    }
  }

  return 0;
}
