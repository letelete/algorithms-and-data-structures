# [Banknoty](https://szkopul.edu.pl/problemset/problem/ucULQRwTgKsiCRWkf0t9GoqH/site/?key=statement)

#### OI stage II

#### Memory limit 64 MB

---

#### Score 100/100

### Complexity

#### Time: O(n\*k)

#### Space: O(n\*k)

---

```C++
#include <bits/stdc++.h>

void optimize_io() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);
}

template <typename T>
using v = std::vector<T>;

#define MAX_COINS 20000

int main() {
  optimize_io();

  int coins_size, sum, min_nominal;
  min_nominal = INT_MAX;
  std::cin >> coins_size;

  v<int> nominals(coins_size);
  v<int> quantity(coins_size);
  for (int& nominal : nominals) {
    std::cin >> nominal;
    min_nominal = std::min(min_nominal, nominal);
  }
  for (int& q : quantity) std::cin >> q;
  std::cin >> sum;

  v<v<int>> coins_left(sum + 1, v<int>(coins_size, 0));
  for (int i = 0; i < coins_size; ++i) coins_left[0][i] = quantity[i];

  v<int> dp(sum + 1, sum + 1);
  dp[0] = 0;

  struct Combination {
    int nominal_index;
    int coins_used;
  } combination;

  for (int i = min_nominal; i <= sum; ++i) {
    combination.coins_used = INT_MAX;
    combination.nominal_index = -1;
    for (int j = 0, coins_used; j < coins_size; ++j) {
      if (i >= nominals[j]) {
        if (coins_left[i - nominals[j]][j] > 0) {
          coins_used = dp[i - nominals[j]] + 1;
          if (coins_used < combination.coins_used) {
            combination.coins_used = coins_used;
            combination.nominal_index = j;
          }
        }
      }
    }
    if (combination.nominal_index != -1) {
      coins_left[i] = coins_left[i - nominals[combination.nominal_index]];
      --coins_left[i][combination.nominal_index];
      dp[i] = combination.coins_used;
    }
  }

  std::cout << dp[sum] << "\n";
  for (int i = 0, coin_delta; i < coins_size; ++i) {
    coin_delta = coins_left[0][i] - coins_left[sum][i];
    std::cout << coin_delta << " ";
  }

  return 0;
}
```
