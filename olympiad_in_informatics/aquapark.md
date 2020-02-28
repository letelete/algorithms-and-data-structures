# [Aquapark](https://szkopul.edu.pl/problemset/problem/J4wIQqR4YCpTUr-d-in1DKnt/site/?key=statement)

#### OIG Stage III

#### Memory limit 128 MB

---

#### Score 56/100

### Complexity

#### Time: O(n \* k)

- n - amount of guards.
- k - maximal horizontal range of pools that nth guard takes care of.

#### Space: O(n^2)

---

```C++
/**
  1	OK	0.00s / 0.10s	8 / 8
  2	OK	0.00s / 0.10s	8 / 8
  3	OK	0.00s / 0.10s	8 / 8
  4	OK	0.07s / 0.30s	8 / 8
  5	OK	0.08s / 0.30s	8 / 8
  6	OK	0.11s / 0.40s	8 / 8
  7	OK	0.70s / 1.00s	8 / 8
  8	Zła odpowiedź	0.31s / 1.00s	0 / 8
  9	Przekroczenie limitu czasu	-.--s / 2.50s	0 / 9
  10	Przekroczenie limitu czasu	-.--s / 2.50s	0 / 9
  11	Przekroczenie limitu czasu	-.--s / 3.50s	0 / 9
  12	Przekroczenie limitu czasu	-.--s / 4.50s	0 / 9
 */
#include <bits/stdc++.h>

#define MIN_N 1
#define MAX_N 1000
#define MIN_R 1
#define MAX_R 1000000
#define PAVEMENT 0

namespace cp {
void optimize_io() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);
}

template <typename T>
using v = std::vector<T>;

template <typename K, typename V>
using umap = std::unordered_map<K, V>;

template <class T>
T min(T a, T b) {
  return a > b ? b : a;
}

template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}

typedef std::string str;

template <class T>
T pow(T a, unsigned b = 2) {
  if (b == 0) return 1;
  unsigned temp = pow(a, b / 2);
  if (b % 2 == 0) return temp * temp;
  return a * temp * temp;
}
}  // namespace cp

using namespace cp;

struct life_guard {
  int x, y, range;
};

int n, r;

// prefix sums of children in all pools. Summed in the vertical way only.
v<v<int>> sums;

int solve(life_guard& guard) {
  int total_children = 0;
  int from_center = guard.range;
  int pos = guard.x - guard.range;
  if (pos < 0) {
    from_center -= abs(pos);
    pos = 0;
  }

  int substract, total_sum;
  while (pos <= guard.x + guard.range && pos < sums.size()) {
    int available_horizontal_steps = guard.range - from_center;
    int total_sum_y = guard.y + available_horizontal_steps;
    int substract_y = guard.y - available_horizontal_steps - 1;
    total_sum =
        sums[pos][total_sum_y >= sums.size() ? sums.size() - 1 : total_sum_y];
    substract = substract_y < 0 ? 0 : sums[pos][substract_y];
    total_children += total_sum - substract;
    from_center += pos < guard.x ? -1 : 1;
    pos++;
  }

  return total_children;
}

int main() {
  optimize_io();

  std::cin >> n >> r;

  sums = v<v<int>>(n, v<int>(n));

  int in;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      std::cin >> in;
      if (y - 1 >= 0) in += sums[x][y - 1];
      sums[x][y] = in;
    }
  }

  for (int i = 0, x, y, range; i < r; ++i) {
    std::cin >> y >> x >> range;
    life_guard guard{x - 1, y - 1, range};
    std::cout << solve(guard) << "\n";
  }

  return 0;
}
```
