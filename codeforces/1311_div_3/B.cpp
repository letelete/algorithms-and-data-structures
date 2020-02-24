
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

int t;
int n, m;

const str yes = "YES";
const str no = "NO";

std::string solve(vint& nums, std::set<int>& p) {
  if (nums.size() <= 1) return yes;
  int right = 1, index;
  while (right < nums.size()) {
    index = right;
    while (index > 0 && nums[index - 1] > nums[index]) {
      std::swap(nums[index - 1], nums[index]);
      if (!p.count(index)) return no;
      --index;
    }
    right++;
  }
  return yes;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  std::cin >> t;
  while (t--) {
    std::cin >> n >> m;
    vint nums(n);
    for (int& n : nums) std::cin >> n;
    std::set<int> p;
    while (m--) {
      int pi;
      std::cin >> pi;
      p.insert(pi);
    }
    std::cout << solve(nums, p) << "\n";
  }
  return 0;
}
