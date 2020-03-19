
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

bool enabled(i64 n) {
  i64 divs = 2;
  for (i64 i = 2; i <= sqrt(n); ++i) {
    divs += n % i == 0;
  }
  return divs % 2 != 0;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  v<i64> input;
  while (true) {
    i64 x;
    std::cin >> x;
    if (x != 0)
      input.push_back(x);
    else
      break;
  }

  for (const i64& x : input) std::cout << (enabled(x) ? "yes" : "no") << "\n";
  return 0;
}
