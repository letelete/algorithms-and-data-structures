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

int main() {
  fastIO;

  int n;
  std::cin >> n;

  while (n--) {
    v<vint> yikes(2, vint(2));
    std::cin >> yikes[0][0] >> yikes[0][1] >> yikes[1][0] >> yikes[1][1];
    bool valid = false;
    for (int i = 0; i < 2 && !valid; ++i) {
      for (int j = 0; j < 2 && !valid; ++j) {
        bool got_l = yikes[0][i] == yikes[1][j];
        bool got_s = yikes[0][i ? 0 : 1] + yikes[1][j ? 0 : 1] == yikes[0][i];
        valid = got_l && got_s;
      }
    }
    std::cout << (valid ? "Yes\n" : "No\n");
  }

  return 0;
}
