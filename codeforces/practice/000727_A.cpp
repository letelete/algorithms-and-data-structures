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

v<i64> steps;

bool solve(i64 a, i64 b) {
  if (b < a) return false;

  steps.push_back(b);
  if (a == b) return true;

  if (b % 2 == 0) {
    b /= 2;
  } else if ((b - 1) % 10 == 0) {
    b = (b - 1) / 10;
  } else {
    return false;
  }

  return solve(a, b);
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  i64 a, b;
  std::cin >> a >> b;
  bool solvable = solve(a, b);
  if (solvable) {
    std::cout << "YES\n" << steps.size() << "\n";
    for (int i = steps.size() - 1; i >= 0; --i) {
      std::cout << steps[i] << " ";
    }
    std::cout << "\n";
  } else {
    std::cout << "NO\n";
  }
  return 0;
}
