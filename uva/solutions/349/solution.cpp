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

bool solve(int step, int mod) {
  int x = 0;
  std::unordered_set<int> seen;
  for (int i = 0; i < mod; ++i) {
    int next = (x + step) % mod;
    if (seen.count(next) || next < 0 || next >= mod) {
      return false;
    }
    seen.insert(next);
    x = next;
  }
  return seen.size() == mod;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int step, mod;
  while (std::cin >> step >> mod) {
    std::cout << std::setw(10) << step << std::setw(10) << mod << "    ";
    std::cout << (solve(step, mod) ? "Good Choice" : "Bad Choice") << "\n\n";
  }

  return 0;
}
