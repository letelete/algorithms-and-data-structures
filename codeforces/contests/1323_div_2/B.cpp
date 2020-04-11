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

v<i64> sum(vint a) {
  v<i64> ans(a.size() + 1);
  for (i64 left = 0; left < a.size();) {
    if (a[left] == 0) {
      ++left;
      continue;
    }
    i64 right = left;
    while (right < a.size() && a[right] == 1) {
      ++right;
    }
    for (i64 size = 1; size <= right - left; ++size) {
      ans[size] += right - left - size + 1;
    }
    left = right;
  }
  return ans;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n, m, k;

  std::cin >> n >> m >> k;

  vint a(n);
  vint b(m);

  for (int& x : a) std::cin >> x;
  for (int& x : b) std::cin >> x;

  i64 total = 0;

  v<i64> asum = sum(a);
  v<i64> bsum = sum(b);
  for (const auto& x : asum) std::cout << x << " ";
  std::cout << " \n";
  for (const auto& x : bsum) std::cout << x << " ";
  std::cout << " \n";
  for (i64 i = 1; i < asum.size(); ++i) {
    if (k % i == 0 && k / i <= m) {
      total += asum[i] * bsum[k / i];
    }
  }

  std::cout << total << "\n";
  return 0;
}
