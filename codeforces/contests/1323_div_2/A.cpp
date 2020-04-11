
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

struct answer {
  int value = -1;
  pint index{-1, -1};
};

answer solve(int k) {
  int first_index = -1;
  vint nums(k);
  for (int& x : nums) std::cin >> x;
  for (int i = 0; i < k; ++i) {
    if (nums[i] % 2 == 0) {
      return answer{1, {i + 1, i + 1}};
    } else {
      if (first_index == -1) {
        first_index = i;
      } else {
        return answer{2, {first_index + 1, i + 1}};
        break;
      }
    }
  }
  return answer{};
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;

  while (n--) {
    int k;
    std::cin >> k;
    answer ans = solve(k);
    std::cout << ans.value;
    if (ans.value != -1) std::cout << "\n" << ans.index.first << " ";
    if (ans.index.second != ans.index.first) std::cout << ans.index.second;
    std::cout << "\n";
  }

  return 0;
}
