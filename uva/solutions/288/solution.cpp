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

#define MAXN 25

int n;
v<vint> image;

v<v<bool>> visited;

bool perform_search(int i, int j) { return image[i][j] == 1 && !visited[i][j]; }

void dfs(int top, int left) {
  for (int i = top - 1; i <= top + 1; ++i) {
    for (int j = left - 1; j <= left + 1; ++j) {
      if (perform_search(i, j)) {
        visited[i][j] = true;
        dfs(i, j);
      }
    }
  }
}

int solve() {
  int count = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (perform_search(i, j)) {
        dfs(i, j);
        count++;
      };
    }
  }
  return count;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int t = 1;
  while (std::cin >> n) {
    image = v<vint>(n + 2, vint(n + 2));
    visited = v<v<bool>>(n + 2, v<bool>(n + 2, false));
    for (int i = 1; i <= n; ++i) {
      str in;
      std::cin >> in;
      for (int j = 1; j <= n; ++j) {
        char cur = in[j - 1] - '0';
        image[i][j] = cur;
      }
    }

    int eagles = solve();
    std::cout << "Image number " << t++ << " contains " << eagles
              << " war eagles.\n";
  }

  return 0;
}
