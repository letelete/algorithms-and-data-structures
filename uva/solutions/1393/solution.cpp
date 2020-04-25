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

umap<char, int> path{{'@', 0}, {'I', 1}, {'E', 2}, {'H', 3},
                     {'O', 4}, {'V', 5}, {'A', 6}, {'#', 7}};

struct data {
  char id;
  pint pos;
};

struct compare {
  bool operator()(const data& a, const data& b) {
    return path[a.id] > path[b.id];
  };
};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int t;
  std::cin >> t;
  while (t--) {
    int m, n;
    std::cin >> m >> n;

    std::priority_queue<data, v<data>, compare> q;
    for (int i = 0; i < m; ++i) {
      str x;
      std::cin >> x;
      for (int j = 0; j < n; ++j) {
        if (path.find(x[j]) != path.end()) {
          data d = data{x[j], pint{i, j}};
          q.push(d);
        }
      }
    }

    pint pos = q.top().pos;
    q.pop();

    bool add_space = false;
    while (!q.empty()) {
      pint next = q.top().pos;
      q.pop();
      int vertical_diff = next.first - pos.first;
      int horizontal_diff = next.second - pos.second;
      if (vertical_diff != 0) {
        std::cout << (add_space ? " " : "") << "forth";
      }
      if (horizontal_diff != 0) {
        str message = horizontal_diff > 0 ? "right" : "left";
        int count = abs(horizontal_diff) - 1;
        std::cout << (add_space ? " " : "") << message;
        add_space = true;
        while (count--) std::cout << (add_space ? " " : "") << message;
      }
      pos = next;
      add_space = true;
    }
    std::cout << "\n";
  }

  return 0;
}
