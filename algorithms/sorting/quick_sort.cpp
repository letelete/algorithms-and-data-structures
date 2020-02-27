
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

vint quicksort(vint arr) {
  if (arr.size() <= 1) return arr;
  int pivot = arr.size() - 1;
  int i = -1, j = 0;
  for (; j < pivot; ++j) {
    if (arr[j] < arr[pivot]) std::swap(arr[++i], arr[j]);
  }
  int pivot_home = i + 1;
  std::swap(arr[pivot_home], arr[pivot]);
  vint sorted, left, right;
  if (pivot_home > 0) {
    left = quicksort(vint(arr.begin(), arr.begin() + pivot_home));
    sorted.insert(sorted.begin(), left.begin(), left.end());
  }
  sorted.push_back(arr[pivot_home]);
  if (pivot_home < arr.size() - 1) {
    right = quicksort(vint(arr.begin() + pivot_home + 1, arr.end()));
    sorted.insert(sorted.begin() + pivot_home + 1, right.begin(), right.end());
  }
  return sorted;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  vint in(n);
  for (int& x : in) std::cin >> x;
  vint sorted = quicksort(in);
  for (const int& x : sorted) std::cout << x << " ";
  return 0;
}
