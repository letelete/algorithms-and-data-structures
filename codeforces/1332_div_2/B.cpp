
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

int t, n;
umap<int, vint> g;
v<bool> vis;
vint groups;
vint input;

umap<int, vint> divisors_cached;

vint divisors(int num) {
  if (!divisors_cached[num].empty()) return divisors_cached[num];
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      if (num / i == i) {
        divisors_cached[num].push_back(i);
      } else {
        divisors_cached[num].push_back(i);
        divisors_cached[num].push_back(num / i);
      }
    }
  }
  return divisors_cached[num];
}

void dfs(int node, int group) {
  vis[node] = true;
  groups[node] = group;
  for (const auto& next : g[node]) {
    vis[next] = true;
    groups[next] = group;
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::cin >> t;
  while (t--) {
    std::cin >> n;

    g = {};
    input = vint(n);
    vis = v<bool>(1001, false);
    groups = vint(1001);

    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      input[i] = x;
      vint x_divisors = divisors(x);
      std::cout << x << ": ";
      for (const int& d : x_divisors) {
        g[d].push_back(x);
        std::cout << d << " ";
      }
      std::cout << "\n";
    }
    int group = 0;
    for (int i = 2; i <= 1000; ++i) {
      if (!g[i].empty() && !vis[g[i].front()]) {
        group++;
        dfs(i, group);
      }
    }
    std::cout << group << "\n";
    for (int i = 0; i < n; ++i) std::cout << groups[input[i]] << " ";
    std::cout << "\n";
  }
  return 0;
}
