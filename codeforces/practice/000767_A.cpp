
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

  vint nums(n + 1);
  nums[0] = n + 1;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    nums[x] = i;
  }

  int index = 0;
  for (int i = n; i > 0;) {
    while (nums[i] <= index) {
      std::cout << i << " ";
      --i;
    }
    if (nums[i] > index) {
      std::cout << "\n";
    }
    ++index;
  }
  return 0;
}
