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

// 10^250 * 10^250 = 10^(250 + 250) = |10^500| = 600
#define MAX_LEN 600

pint partite(int num) {
  int add = 0, stay = num;
  if (num >= 10) {
    stay = num % 10;
    add = (num - stay) / 10;
  }
  return pint{add, stay};
}

int toint(char c) { return int(c - '0'); }

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  str a, b;
  while (std::cin >> a >> b) {
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    vint res(MAX_LEN, 0);
    for (int i = 0; i < a.length(); ++i) {
      for (int j = 0; j < b.length(); ++j) {
        res[i + j] += toint(a[i]) * toint(b[j]);
      }
    }

    pint pair = {0, 0};
    for (int i = 0; i < res.size(); ++i) {
      pair = partite(res[i] += pair.first);
      res[i] = pair.second;
    }

    for (int i = res.size() - 1, spot = 0; i >= 0; --i) {
      if (!spot && res[i] != 0 || i == 0) spot = true;
      if (spot) std::cout << res[i];
    }

    std::cout << "\n";
  }
  return 0;
}
