#include <bits/stdc++.h>

#pragma GCC target("popcnt")

#define fastIO      \
  std::cin.tie(0);  \
  std::cout.tie(0); \
  std::ios::sync_with_stdio(0);

template <typename T>
using v = std::vector<T>;
template <typename T>
using q = std::queue<T>;
template <typename T>
using pq = std::priority_queue<T>;
template <typename T>
using set = std::set<T>;
template <typename T>
using uset = std::unordered_set<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
template <typename K, typename V>
using map = std::map<K, V>;
template <typename T, typename K>
using pair = std::pair<T, K>;

typedef long long int i64;
typedef unsigned long long ui64;

typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<char> vchar;
typedef std::vector<std::string> vstr;
typedef std::pair<int, int> pint;

int no() {
  std::cout << "no\n";
  return 0;
}

int main() {
  fastIO;

  int n;
  std::cin >> n;
  vint nums(n);
  for (int& x : nums) std::cin >> x;

  int index = 0, last = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] > nums[index]) {
      index = i;
    } else if (nums[i] < nums[index]) {
      break;
    }
  }

  if (index == nums.size() - 1 || nums.size() == 1) {
    std::cout << "yes\n1 1\n";
    return 0;
  }

  for (int i = index + 1; i < nums.size(); ++i) {
    if (nums[i] <= nums[i - 1]) last = i;
    if (nums[i] > nums[i - 1] || last == nums.size() - 1) {
      if (index > 0 && nums[index - 1] > nums[last]) return no();
      if (last != i && nums[index] > nums[i]) return no();
      break;
    }
  }

  for (int i = last + 1; i + 1 < nums.size(); ++i) {
    if (nums[i] > nums[i + 1]) return no();
  }

  std::cout << "yes\n" << index + 1 << " " << last + 1 << "\n";
  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */

/** ⚠ Common mistakes
 * 1. No checking for integer overflow in the addition operation
 * (use i64 instead)
 */
