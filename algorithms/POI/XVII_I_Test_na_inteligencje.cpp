/**
 * Test na inteligencję
 * XVII OI stage I. Memory limit: 64 MB.
 * Score: 20/100
 *
 * https://szkopul.edu.pl/problemset/problem/Ak4wWPkNtHpF-OiulN1gixfW/site/?key=statement
 */

#include <bits / stdc++.h>

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

  template <class T>
  T pow(T a, unsigned b = 2) {
    if (b == 0) return 1;
    unsigned temp = pow(a, b / 2);
    if (b % 2 == 0) return temp * temp;
    return a * temp * temp;
  }
};  // namespace cp

using namespace cp;

int m, n;
v<int> a;
v<std::queue<int>> b;

int main() {
  optimize_io();

  std::cin >> m;
  a = v<int>(m);
  for (int& am : a) std::cin >> am;

  std::cin >> n;
  b = v<std::queue<int>>(n);
  for (std::queue<int>& b_queue : b) {
    int k;
    std::cin >> k;
    while (k--) {
      int arg;
      std::cin >> arg;
      b_queue.push(arg);
    }
  }

  for (const int& am : a) {
    for (std::queue<int>& q : b) {
      if (q.size() <= m && !q.empty() && q.front() == am) {
        q.pop();
      }
    }
  }

  for (const std::queue<int>& q : b) std::cout << (q.empty() ? "TAK" : "NIE") << "\n";

  return 0;
}