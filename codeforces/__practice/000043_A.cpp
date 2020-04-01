
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
  str team1 = "-1", team2 = "-1";
  int team1pts = 0;
  for (int i = 0; i < n; ++i) {
    str t;
    std::cin >> t;
    if (team1 == "-1") {
      team1 = t;
    } else if (team2 == "-1" && t != team1) {
      team2 = t;
    }
    if (t == team1) team1pts++;
  }
  std::cout << (team1pts > n / 2 ? team1 : team2) << "\n";
  return 0;
}
