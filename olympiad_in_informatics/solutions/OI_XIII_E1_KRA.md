# [OI_XIII_E1_KRA](https://szkopul.edu.pl/problemset/problem/fYXVXOreVxlXTRoHZJXyXF2l/site/?key=statement)

---

### Complexity

`@param parts = K`

#### Time: O(m \* log(|K|))

#### Space: O(|K|)

---

```C++
#include <bits/stdc++.h>

#pragma GCC target("popcnt")

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

struct compare {
  bool operator()(const pint& p, const int& key) { return (p.first < key); }
  bool operator()(const int& key, const pint& p) { return key < p.first; }
};

int main() {
  fastIO;

  int n, m, last_free_index;
  // width;index;
  v<pint> parts;
  uset<int> spotted_widths;
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int width;
    std::cin >> width;
    if (spotted_widths.count(width)) continue;
    spotted_widths.insert(width);
    parts.push_back(std::make_pair(width, i));
  }

  std::sort(parts.begin(), parts.end());
  last_free_index = n;

  for (int i = 0; i < m; ++i) {
    int next;
    std::cin >> next;
    auto it = std::lower_bound(parts.begin(), parts.end(), next, compare());
    if (it == parts.begin()) {
      last_free_index--;
      continue;
    }
    it--;
    pint disk = *it;
    if (disk.second > last_free_index) {
      last_free_index--;
      continue;
    }
    int next_disk_index = disk.second - 1;
    last_free_index = next_disk_index - 1;
  }

  std::cout << ((last_free_index < 0) ? 0 : (last_free_index + 1)) << "\n";

  return 0;
}
```
