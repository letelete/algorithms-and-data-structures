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

const int mins_before_party = 4 * 60;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  int cp_limit = mins_before_party - k;
  int cp_mins = 0, i = 1, total = 0;
  while (cp_mins < cp_limit && total < n) {
    cp_mins += (i++) * 5;
    ++total;
  }

  if (cp_mins > cp_limit) total--;
  std::cout << total << "\n";

  return 0;
}