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

const str keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  umap<char, int> index;
  for (int i = 0; i < keyboard.length(); ++i) index[keyboard[i]] = i;

  char dir;
  str sentence, out;
  std::cin >> dir >> sentence;

  int shift = dir == 'R' ? -1 : 1;

  out.reserve(sentence.length());

  for (const char& x : sentence) {
    int xindex = index[x];
    out.push_back(keyboard[xindex + shift]);
  }

  std::cout << out << "\n";

  return 0;
}
