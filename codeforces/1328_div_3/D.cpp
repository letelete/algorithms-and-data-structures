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

  int n;
  std::cin >> n;
  while (n--) {
    int t;
    std::cin >> t;
    vint animals(t);
    for (int& x : animals) std::cin >> x;

    vint colors(t, 1);
    int cur_color = 1, colors_amount = 1, last_pair_el = -1;
    bool modify_pair = false;

    for (int i = 1; i < t; ++i) {
      if (animals[i - 1] != animals[i]) {
        colors_amount = 2;
        cur_color += cur_color == 2 ? -1 : 1;
      } else {
        last_pair_el = i;
      }
      colors[i] = cur_color;
    }

    bool last_animal_color_conflict =
        colors.front() == colors.back() && animals.back() != animals.front();

    if (last_animal_color_conflict) {
      if (last_pair_el != -1) {
        modify_pair = true;
      }
      if (!modify_pair) {
        colors[colors.size() - 1] = 3;
        colors_amount = 3;
      }
    }

    std::cout << colors_amount << "\n";
    for (int i = 0; i < t; ++i) {
      int color = colors[i];
      if (modify_pair && i >= last_pair_el) color = color == 1 ? 2 : 1;
      std::cout << color << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
