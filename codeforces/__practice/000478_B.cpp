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

i64 n, m;

void ans(i64 min, i64 max) { std::cout << min << " " << max << "\n"; }

i64 pairs_num(i64 num) {
  if (num <= 1) return 0;
  return (num * (num - 1)) / 2;
}

i64 max() {
  i64 ppl = (n - m) + 1;
  return pairs_num(ppl);
}

i64 min() {
  i64 p = n / m, k = n % m;
  i64 total;
  if (n % m != 0) {
    total = ((m - k) * pairs_num(p)) + (k * pairs_num(p + 1));
  } else {
    total = (m * pairs_num(p));
  }
  return total;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> n >> m;

  if (n == m) {
    ans(0, 0);
  } else {
    ans(min(), max());
  }

  return 0;
}
