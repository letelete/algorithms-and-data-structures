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

int t, a, b, c;

struct answer {
  int a, b, c, total = INT_MAX;
  void print() {
    std::cout << total << "\n";
    std::cout << a << " " << b << " " << c << "\n";
  }
};

void solve() {
  int optimal_steps = INT_MAX;
  answer ans;
  for (int _A = 1; _A <= 2 * a; ++_A) {
    // So we are only interested in finding a C now
    for (int _B = _A; _B <= 2 * b; _B += _A) {
      // verify both edges and get a value closer to one of them
      // for instance: 5 & 19; 19 / 5 = 3 => 3 * 5 = 15;
      // or: 19 / 5 = 3; 4 * 5 = 20; 20 - 19 = 1;
      // abs(19 - 20) < abs(19-15)
      for (int edge = 0; edge < 2; ++edge) {
        int _C = _B * (c / _B) + edge * _B;
        int cur_steps = abs(a - _A) + abs(b - _B) + abs(c - _C);
        if (cur_steps < ans.total) ans = {_A, _B, _C, cur_steps};
      }
    }
  }
  ans.print();
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  std::cin >> t;

  while (t--) {
    std::cin >> a >> b >> c;
    solve();
  }

  return 0;
}
