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

  int n;
  std::cin >> n;
  if (n % 2 != 0) {
    std::cout << "-1\n";
    return 0;
  }

  vchar b(n);
  int valid = 0;
  for (char& c : b) {
    std::cin >> c;
    valid += (c == '(') ? 1 : -1;
  };

  if (valid != 0) {
    std::cout << "-1\n";
    return 0;
  }

  bool minus = false;
  int sum = 0;
  int total = 0;
  int last = 0;
  for (int i = 0; i < n; ++i) {
    if (sum == 0 && b[i] == ')') {
      minus = true;
      last = i;
    }
    sum += (b[i] == ')') ? -1 : 1;
    if (sum == 0 && minus) {
      minus = false;
      total += i - last + 1;
    }
  }

  std::cout << total << "\n";
  return 0;
}
