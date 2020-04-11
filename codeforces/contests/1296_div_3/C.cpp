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

pint stepbehav(char step) {
  int x = 0, y = 0;
  if (step == 'L') x = -1;
  if (step == 'R') x = 1;
  if (step == 'U') y = 1;
  if (step == 'D') y = -1;
  return std::make_pair(x, y);
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;

    str path;
    path.reserve(n);
    std::cin >> path;

    pint pos{0, 0};
    std::map<pint, int> cache{{pos, 0}};
    pint min_pint = pos;
    int min_length = INT_MAX;
    int index = 0;
    for (const char& step : path) {
      ++index;
      pint behav = stepbehav(step);
      pos.first += behav.first;
      pos.second += behav.second;
      if (cache.find(pos) != cache.end()) {
        int cur_length = index - cache[pos] + 1;
        if (cur_length < min_length) {
          min_pint.first = cache[pos] + 1;
          min_pint.second = index;
          min_length = cur_length;
        }
      }
      cache[pos] = index;
    }
    if (min_length == INT_MAX) {
      std::cout << -1 << "\n";
    } else {
      std::cout << min_pint.first << " " << min_pint.second << "\n";
    }
  }

  return 0;
}
