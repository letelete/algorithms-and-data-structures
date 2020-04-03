
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

  vint nums(n);
  for (int i = 0; i < n; ++i) std::cin >> nums[i];

  for (int i = 0; i < n; ++i) {
    int min = std::min(i > 0 ? abs(nums[i] - nums[i - 1]) : INT_MAX,
                       i < n - 1 ? abs(nums[i] - nums[i + 1]) : INT_MAX);
    int max = std::max(abs(nums[i] - nums[0]), abs(nums[i] - nums[n - 1]));
    std::cout << min << " " << max << "\n";
  }

  return 0;
}
