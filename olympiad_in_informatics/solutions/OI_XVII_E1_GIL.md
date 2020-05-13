# [OI_XVII_E1_GIL]()

---

#### Score 100/100

### Complexity

```
E - Nodes's  Edges
```

#### Time: O(n \* |En|)

#### Space: O(n \* m)

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

int n, m;

v<bool> s, k, vis;
v<vint> g;

map<int, char> pick;

i64 k_cnt = 0, s_cnt = 0;

const char K_PICK = 'K';
const char S_PICK = 'S';
const char N_PICK = 'N';

void resolve(int node) {
  if (vis[node]) return;
  vis[node] = true;
  bool k_pick = false;
  if (!k[node]) {
    k_pick = true;
    k[node] = true;
    k_cnt++;
    pick[node] = K_PICK;
  } else {
    if (!s[node]) s_cnt++;
    pick[node] = S_PICK;
    s[node] = true;
  }
  for (auto& x : g[node]) {
    if (k_pick) {
      k_cnt += !k[x];
      k[x] = true;
    } else {
      s_cnt += !s[x];
      s[x] = true;
    }
  }
}

int main() {
  fastIO;

  std::cin >> n >> m;
  s = k = vis = v<bool>(n + 1, false);
  g = v<vint>(n + 1);
  for (int i = 0; i < m; ++i) {
    int from, to;
    std::cin >> from >> to;
    g[from].push_back(to);
    g[to].push_back(from);
  }

  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    resolve(i);
  }
  if (k_cnt != s_cnt) {
    std::cout << "NIE\n";
    return 0;
  }
  std::cout << "TAK\n";
  for (const auto& x : pick) {
    std::cout << x.second << "\n";
  }

  return 0;
}
```
