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

  vint nums(n), flip(n);

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
    sum += nums[i];
    flip[i] = nums[i] == 1 ? -1 : 1;
  }

  int max_so_far = flip[0];
  int curr_max = flip[0];

  for (int i = 1; i < flip.size(); i++) {
    curr_max = std::max(flip[i], curr_max + flip[i]);
    max_so_far = std::max(max_so_far, curr_max);
  }

  std::cout << sum + max_so_far << "\n";

  return 0;
}
