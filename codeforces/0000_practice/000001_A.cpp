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

i64 m, n, a;

i64 need(i64 size, i64 rect) {
  if (size <= rect) return 1;
  return (size / rect) + (size % rect != 0);
}

i64 solve() {
  i64 m_need = need(m, a);
  i64 n_need = need(n, a);
  return m_need + (n_need > 1 ? (m_need * (n_need - 1)) : 0);
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> m >> n >> a;
  std::cout << solve() << "\n";

  return 0;
}