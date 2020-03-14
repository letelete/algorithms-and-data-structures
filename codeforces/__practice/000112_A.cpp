
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

// Three liner:
// char a[101], b[101];
// std::cin >> a >> b;
// std::cout << stricmp(a, b) << "\n";

// Or you can just solve it like that and have some more fun with chars (:

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int alen = 0, blen = 0, ans = -2;
  char a[101], b[101];
  for (int i = 0; i < 101; ++i) a[i] = b[i] = 0;

  std::cin >> a >> b;

  for (int i = 0; i < 101; ++i) {
    char cha = tolower(a[i]), chb = tolower(b[i]);
    if (cha != chb) {
      ans = cha > chb ? 1 : -1;
      break;
    }
  }
  std::cout << (ans == -2 ? 0 : ans) << "\n";

  return 0;
}
