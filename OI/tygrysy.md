# [Tygrysy](https://szkopul.edu.pl/problemset/problem/qIU-rEjDKpMNvQWNfGOxYrO5/site/?key=statementt)

#### OIG stage III

#### Memory limit 32 MB

---

#### Score 100/100

### Complexity

#### Time: O(n)

#### Space: O(k), where k equals to the amount of unique tiger sizes. k == n in worst case.

---

```C++
#include <bits / stdc++.h>

typedef std::pair<int, int> tiger;

int min(const tiger& t) { return (t.first / t.second) + 1; }

int n;
std::map<int, int, std::greater<int>> tigers;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int size, k;
    std::cin >> size >> k;
    if (tigers.find(size) == tigers.end() || k < tigers[size]) {
      tigers[size] = k;
    }
  }

  int total = 1;
  int cur_min = min(tiger{tigers.begin()->first, tigers.begin()->second});
  for (const tiger& t : tigers) {
    if (t.first < cur_min) {
      ++total;
      cur_min = min(t);
    } else {
      cur_min = std::max(cur_min, min(t));
    }
  }

  std::cout << total << "\n";

  return 0;
}
```
