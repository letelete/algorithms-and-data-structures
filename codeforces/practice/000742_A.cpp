
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

// 8 4 2 6
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  vint nums{{8, 4, 2, 6}};
  i64 n;
  std::cin >> n;
  int ind = (n % nums.size()) - 1;
  if (ind < 0) ind = nums.size() - 1;
  std::cout << (!n ? 1 : nums[ind]) << "\n";

  return 0;
}
