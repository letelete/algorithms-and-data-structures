
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

  str song;
  std::cin >> song;
  int window = 3;
  str ss;
  bool space = false;
  for (int i = 0; i < song.length();) {
    if (song[i] == 'W' && song[i + 1] == 'U' && song[i + 2] == 'B') {
      i += window;
      if (space) ss += " ";
      space = false;
    } else {
      ss += song[i];
      ++i;
      space = true;
    }
  }

  std::cout << ss << "\n";

  return 0;
}
