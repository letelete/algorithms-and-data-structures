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

int t, n, m;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> t;

  while (t--) {
    str s;
    std::map<char, int> occurs;
    for (int i = 'a'; i <= 'z'; ++i) occurs[char(i)] = 0;
    int prev = 0, index = 0;

    std::cin >> n >> m;
    std::cin >> s;
    vint reps(m);
    for (int& i : reps) std::cin >> i;

    std::sort(reps.begin(), reps.end());
    while (m > 0) {
      int right_excl = reps[index];
      for (int i = prev; i < right_excl; ++i) {
        occurs[s[i]] += m;
      }
      prev = right_excl;
      --m;
      ++index;
    }

    for (const char& y : s) occurs[y]++;

    for (const auto& p : occurs) std::cout << p.second << " ";
    std::cout << "\n";
  }

  return 0;
}
