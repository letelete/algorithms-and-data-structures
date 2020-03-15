
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

#define chat "CHAT WITH HER!"
#define ignore "IGNORE HIM!"

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::unordered_set<char> seen;
  str nick;
  std::cin >> nick;
  for (const char& c : nick) seen.insert(c);

  std::cout << (seen.size() % 2 == 0 ? chat : ignore) << "\n";

  return 0;
}
