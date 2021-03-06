
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

  int n, danik = 0, anton = 0;
  str score;
  std::cin >> n;
  std::cin >> score;
  for (int i = 0; i < n; ++i) {
    if (score[i] == 'D')
      danik++;
    else
      anton++;
  }
  std::cout << (danik == anton ? "Friendship"
                               : danik > anton ? "Danik" : "Anton")
            << "\n";
  return 0;
}
