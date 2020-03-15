
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

const int letters_length = 26;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  str word;
  std::cin >> word;
  int moves = 0;
  char prev = 'a';
  for (int i = 0; i < word.length(); ++i) {
    int diff = abs(prev - word[i]);
    moves += std::min(diff, letters_length - diff);
    prev = word[i];
  }

  std::cout << moves << "\n";

  return 0;
}
