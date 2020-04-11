
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

  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int x, y, x1, x2, y1, y2;
    std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    int hmv = x2 - x1;
    int vmv = y2 - y1;
    int hdiff = x + (b - a);
    int vdiff = y + (d - c);
    bool okh = (hdiff >= x1 && hdiff <= x2);
    bool okv = (vdiff >= y1 && vdiff <= y2);
    if (hmv < 1 && a + b > 0) okh = false;
    if (vmv < 1 && d + c > 0) okv = false;
    std::cout << ((okh && okv) ? "Yes" : "No") << "\n";
  }

  return 0;
}
