
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
const int maybe = 0;
const int rated = 1;
const int unrated = -1;

umap<int, str> ans{{maybe, "maybe"}, {rated, "rated"}, {unrated, "unrated"}};

int n;

int solve() {
  pint cur, prev;
  bool unr = false;
  std::cin >> prev.first >> prev.second;
  for (int i = 1; i < n; ++i) {
    std::cin >> cur.first >> cur.second;
    if (cur.first != cur.second || prev.first != prev.second) return rated;
    if (prev.first < cur.first) unr = true;
    prev = cur;
  }
  return unr ? unrated : maybe;
}
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> n;
  int res = solve();
  std::cout << ans[res] << "\n";
}
