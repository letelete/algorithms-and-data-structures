
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

  int t;
  std::cin >> t;
  while (t--) {
    v<bool> nums(201, false);
    int n, x;
    std::cin >> n >> x;
    for (int i = 0; i < n; ++i) {
      int y;
      std::cin >> y;
      nums[y] = true;
    }

    int max = 1;
    for (int i = 1; x >= 0; ++i) {
      if (!nums[i]) {
        if (x == 0) break;
        x--;
      }
      max = i;
    }
    std::cout << max << "\n";
  }

  return 0;
}
