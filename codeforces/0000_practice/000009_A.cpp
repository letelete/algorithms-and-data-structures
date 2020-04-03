
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

int GCD(int a, int b) {
  int high = std::max(a, b), low = std::min(a, b);
  while (low != 0) {
    int aux = high % low;
    high = low;
    low = aux;
  }
  return high;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  const int max = 6;

  int a, b;
  std::cin >> a >> b;

  int starter = std::max(a, b);
  int den_ans = max, num_ans = den_ans - starter + 1;
  int gcd = GCD(den_ans, num_ans);
  den_ans /= gcd;
  num_ans /= gcd;
  std::cout << num_ans << "/" << den_ans << "\n";

  return 0;
}
