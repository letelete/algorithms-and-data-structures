
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

const int MAXM = 50;
v<bool> primes(MAXM + 1, true);

void sieve_primes() {
  for (int i = 2; i < sqrt(MAXM); ++i) {
    for (int j = 2; j <= MAXM; ++j) {
      int next = j * i;
      if (next > MAXM) continue;
      primes[next] = false;
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  sieve_primes();

  int n, m;
  std::cin >> n >> m;
  bool m_is_next_prime = primes[m];
  for (int i = n + 1; i < m; ++i) {
    if (primes[i]) {
      m_is_next_prime = false;
      break;
    }
  }

  std::cout << (m_is_next_prime ? "YES" : "NO") << "\n";

  return 0;
}
