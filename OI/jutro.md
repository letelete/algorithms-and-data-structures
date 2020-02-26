# [Jutro](https://szkopul.edu.pl/problemset/problem/EMB5uNAIW1GVi_U23U-pqurR/site/?key=statement)

#### AMPPZ

#### Memory limit 128 MB

---

#### Score 100/100

### Complexity

#### Time: O(nlogn)

#### Space: O(n)

---

```C++
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

int n;
v<pint> tasks;
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  auto compare = [](const pint& a, const pint& b) {
    return a.second < b.second;
  };

  std::cin >> n;
  tasks = v<pint>(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> tasks[i].first >> tasks[i].second;
  }
  std::sort(tasks.begin(), tasks.end(), compare);
  int max = tasks.front().second, min = max - tasks.front().first;
  min++;
  max++;
  int days = tasks.front().first;
  for (int i = 1; i < n; ++i) {
    pint& cur = tasks[i];
    days += cur.first;
    int mincur = cur.second - cur.first + 1;
    if (mincur < max) {
      int diff = max - mincur;
      min -= diff;
    }
    max = min + days;
  }

  std::cout << min - 1 << "\n";

  return 0;
}
```
