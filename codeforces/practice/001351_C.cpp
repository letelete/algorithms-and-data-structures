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

umap<char, int> dx{{'N', 0}, {'E', 1}, {'S', 0}, {'W', -1}};
umap<char, int> dy{{'N', 1}, {'E', 0}, {'S', -1}, {'W', 0}};

typedef std::tuple<int, int, int, int> path;

int main() {
  fastIO;

  int n;
  str p;
  set<path> vis;

  std::cin >> n;

  while (n--) {
    std::cin >> p;

    int x{0}, y{0}, t{0};

    vis.clear();

    for (const auto& next : p) {
      int xs = x, ys = y;
      x += dx[next];
      y += dy[next];
      t += vis.count(path{xs, ys, x, y}) ? 1 : 5;
      vis.insert(path{x, y, xs, ys});
      vis.insert(path{xs, ys, x, y});
    }

    std::cout << t << "\n";
  }

  return 0;
}
