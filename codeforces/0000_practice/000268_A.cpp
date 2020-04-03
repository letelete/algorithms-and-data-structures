
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

const int MAXN = 101;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n, total = 0, max_input = 1;
  std::cin >> n;

  vint home(MAXN + 1, 0), guest(MAXN + 1, 0);
  for (int i = 0, h, g; i < n; ++i) {
    std::cin >> h >> g;
    home[h]++;
    guest[g]++;
    max_input = std::max(max_input, std::max(g, h));
  }

  for (int i = 1; i <= max_input; ++i) total += home[i] * guest[i];

  std::cout << total << "\n";

  return 0;
}
