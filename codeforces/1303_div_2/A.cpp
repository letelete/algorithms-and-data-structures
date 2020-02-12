#include <bits/stdc++.h>

void solve(std::string& str) {
  int total = 0, last_one = -1;
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == '1') {
      if (last_one != -1) {
        total += i - last_one - 1;
      }
      last_one = i;
    }
  }
  std::cout << total << "\n";
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string str;
    std::cin >> str;
    solve(str);
  }
  return 0;
}