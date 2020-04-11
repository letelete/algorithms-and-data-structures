
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

i64 t, x;

i64 gcd(i64 a, i64 b) {
  i64 c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

i64 lcm(i64 a, i64 b) { return (a * b) / gcd(a, b); }

bool check(i64 a, i64 b) { return (gcd(a, b) + lcm(a, b) == x); }

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> t;
  while (t--) {
    std::cin >> x;
    i64 g, l, ans1 = -1, ans2 = -1;
    for (i64 i = 1; i <= x, ans1 == -1 && ans2 == -1; ++i) {
      for (i64 j = x; j >= 1, ans1 == -1 && ans2 == -1; --j) {
        if (check(i, j)) {
          ans1 = i;
          ans2 = j;
        } else if (check(i, i)) {
          ans1 = ans2 = i;
        } else if (check(j, j)) {
          ans1 = ans2 = j;
        }
      }
    }
    std::cout << ans1 << " " << ans2 << "\n";
  }

  return 0;
}
