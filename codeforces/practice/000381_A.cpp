
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

  int maxsum = 0, l = 0, r = n - 1, ser = 0;

  for (int& x : nums) {
    std::cin >> x;
    maxsum += x;
  }

  bool ser_move = true;
  while (l <= r) {
    if (ser_move) ser += std::max(nums[l], nums[r]);
    if (nums[l] > nums[r]) {
      ++l;
    } else {
      --r;
    }
    ser_move = !ser_move;
  }

  std::cout << (ser) << " " << (maxsum - ser) << "\n";
  return 0;
}
