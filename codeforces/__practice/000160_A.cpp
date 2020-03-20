
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

  int n, total_sum = 0, my_coins = 0, amount = 0;
  std::cin >> n;
  vint coins(n);
  for (int& x : coins) {
    std::cin >> x;
    total_sum += x;
  }

  std::sort(coins.begin(), coins.end());
  for (int i = n - 1; i >= 0; --i) {
    if (my_coins <= total_sum - my_coins) {
      my_coins += coins[i];
      amount++;
    }
  }

  std::cout << amount << "\n";

  return 0;
}
