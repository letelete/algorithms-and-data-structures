# [Program](https://szkopul.edu.pl/problemset/problem/jvPBZm53yfvDkYKuuxbQvjNe/site/?key=statement)

#### OIG Stage I

#### Memory limit 32 MB

---

#### Score 100/100

### Complexity

#### Time: O(n)

#### Space: O(n)

---

```C++
#include <bits/stdc++.h>

#define MIN_N 1
#define MAX_N 1000000
#define INVALID -1

namespace cp {
void optimize_io() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);
}

template <typename T>
using v = std::vector<T>;

template <typename K, typename V>
using umap = std::unordered_map<K, V>;

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

int n;
str in;
umap<char, char> counter{{'(', ')'}, {'[', ']'}, {'{', '}'}};

int solve() {
  if (n <= 1 || n % 2) return INVALID;

  int max_depth{0}, depth_counter{0};
  std::stack<char> seen;

  for (const char& c : in) {
    max_depth = std::max(depth_counter, max_depth);
    bool top_bracket_counter = !seen.empty() && c == counter[seen.top()];
    bool next_nestedness = counter[c] != '\0';
    if (seen.empty() || next_nestedness) {
      seen.push(c);
      ++depth_counter;
    } else if (top_bracket_counter) {
      seen.pop();
      --depth_counter;
    } else {
      return INVALID;
    }
  }
  return seen.empty() ? max_depth : INVALID;
}

int main() {
  optimize_io();

  std::cin >> n >> in;

  int result = solve();
  if (result == INVALID) std::cout << "NIE\n";
  else std::cout << result << "\n";

  return 0;
}
```
