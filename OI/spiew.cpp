/**
 * Śpiew
 * OIG stage I. Memory limit: 32 MB.
 * Score: 100/100
 *
 * https://szkopul.edu.pl/problemset/problem/JDLRIKmmfMWZ7G1Sy6Ldq7m8/site/?key=statement
 */

#include <bits/stdc++.h>

int n;
std::vector<bool> seats;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::cin >> n;
  seats = std::vector<bool>(n);
  for (int i = 0; i < n; ++i) {
    char type;
    std::cin >> type;
    seats[i] = type == 'Z';
  }

  const int max_limit = 3;
  int total = 0, limit = max_limit;
  for (int i = 0; i < n; ++i) {
    limit -= seats[i];
    bool limit_exceed = !limit;
    bool cant_share_seat = !seats[i] && limit < max_limit;
    bool last_reserved_seat = i + 1 >= n && seats[i];
    if (limit_exceed || cant_share_seat || last_reserved_seat) {
      ++total;
      limit = max_limit;
    }
  }

  std::cout << total << "\n";
  return 0;
}