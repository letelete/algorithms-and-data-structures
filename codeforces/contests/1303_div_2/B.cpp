#include <bits/stdc++.h>

typedef long long int i64;

i64 solve(i64 n, i64 g, i64 b) {
  i64 m = n - (n / 2);
  if (m <= g) return n;
  i64 total = 0, i_g = m / g;
  total += i_g * (g + b);
  m -= i_g * g;
  if (m > 0) {
    total += m;
  } else {
    total -= b;
  }
  if (total < n) {
    total = n;
  }
  return total;
}

int main() {
  int t;
  std::cin >> t;
  i64 n, g, b;
  while (t--) {
    std::cin >> n >> g >> b;
    std::cout << solve(n, g, b) << "\n";
  }
  return 0;
}