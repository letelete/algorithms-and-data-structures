
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

const int max_taxi_capacity = 4;

int n, total = 0;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> n;
  vint groups(n);
  umap<int, int> occurs;

  for (int& x : groups) {
    std::cin >> x;
    ++occurs[x];
  }

  std::sort(groups.begin(), groups.end(), std::greater<int>());

  for (const int& group : groups) {
    int cur_cap = occurs[group] > 0 ? (max_taxi_capacity - group) : 0;
    total += occurs[group]-- > 0;
    for (int index = cur_cap; index > 0; --index) {
      while (occurs[index] > 0 && cur_cap > 0) {
        --occurs[index];
        cur_cap -= index;
      }
    }
  }

  std::cout << total << "\n";

  return 0;
}
