
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

  int n, l, r, x;
  std::cin >> n >> l >> r >> x;

  vint problems(n);
  for (int& problem : problems) std::cin >> problem;

  int ways = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int current = 0, easiest = INT_MAX, hardest = INT_MIN;
    for (int i = 0; i < n; ++i) {
      if (1 & (mask >> i)) {
        int problem = problems[i];
        current += problem;
        easiest = std::min(easiest, problem);
        hardest = std::max(hardest, problem);
      }
    }
    ways += (current >= l && current <= r && hardest - easiest >= x);
  }

  std::cout << ways << "\n";

  return 0;
}
