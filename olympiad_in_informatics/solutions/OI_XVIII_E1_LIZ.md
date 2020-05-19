# [OI_XVIII_E1_LIZ](https://szkopul.edu.pl/problemset/problem/AWhdD7i4V7mupdKWVtpgfGSM/site/?key=statement)

---

#### Time: O(n + m)

#### Space: O(n)

---

```C++
#include <bits/stdc++.h>

#define fastIO      \
  std::cin.tie(0);  \
  std::cout.tie(0); \
  std::ios::sync_with_stdio(0);

template <typename T>
using v = std::vector<T>;
template <typename T>
using q = std::queue<T>;
template <typename T>
using pq = std::priority_queue<T>;
template <typename T>
using set = std::set<T>;
template <typename T>
using uset = std::unordered_set<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
template <typename K, typename V>
using map = std::map<K, V>;
template <typename T, typename K>
using pair = std::pair<T, K>;

typedef long long int i64;
typedef unsigned long long ui64;

typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<char> vchar;
typedef std::vector<std::string> vstr;
typedef std::pair<int, int> pint;

const pint INVALID_PRICE = std::make_pair(-1, -1);

int n, m, total_sum = 0;

v<pint> segments;
str lollipop;

int loli(int at) { return (lollipop[at] == 'T') ? 2 : 1; };

void memoize(int sum, int lo, int hi) {
  segments[sum] = std::make_pair(lo, hi);
  while (sum >= 3) {
    if (loli(lo) == 2) {
      lo++;
    } else if (loli(hi) == 2) {
      hi--;
    } else {
      lo++;
      hi--;
    }
    sum -= 2;
    segments[sum] = std::make_pair(lo, hi);
  }
}

std::tuple<int, int, int> second_sum_with_range() {
  int sum = 0, left_sum, right_sum = -1, left_ptr, right_ptr;
  for (int i = 0; i < n; ++i) {
    sum += loli(i);
    if (loli(i) != 1) continue;
    if (right_sum == -1) {
      right_sum = total_sum - sum;
      right_ptr = i + 1;
    }
    left_sum = sum - loli(i);
    left_ptr = i - 1;
  }
  return (right_sum > left_sum) ? std::make_tuple(right_sum, right_ptr, n - 1)
                                : std::make_tuple(left_sum, 0, left_ptr);
}

void answer_queries() {
  while (m--) {
    int p;
    std::cin >> p;
    if (p >= (int)segments.size() || segments[p] == INVALID_PRICE) {
      std::cout << "NIE\n";
    } else {
      auto seg = segments[p];
      std::cout << (seg.first + 1) << " " << (seg.second + 1) << "\n";
    }
  }
}

int main() {
  fastIO;

  std::cin >> n >> m >> lollipop;
  segments = v<pint>((2 * n) + 1, INVALID_PRICE);

  for (int i = 0; i < n; ++i) total_sum += loli(i);

  memoize(total_sum, 0, n - 1);

  bool only_even_values = (total_sum % n == 0) && (total_sum / n == 2);
  if (only_even_values) {
    answer_queries();
    return 0;
  }

  auto second_sum = second_sum_with_range();
  memoize(std::get<0>(second_sum), std::get<1>(second_sum),
          std::get<2>(second_sum));

  answer_queries();

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
```
