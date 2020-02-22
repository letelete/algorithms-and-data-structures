#include <bits/stdc++.h>

typedef std::pair<int, int> pint;

int n;
std::vector<std::vector<int>> in;
std::vector<std::vector<pint>> dp;

int rect_area(pint a) { return a.first * a.second; }

pint max_pair(pint a, pint b) { return rect_area(a) > rect_area(b) ? a : b; }

int main() {
  std::cin >> n;
  in = std::vector<std::vector<int>>(n, std::vector<int>(n));
  dp = std::vector<std::vector<pint>>(n, std::vector<pint>(n));

  for (auto& x : in) {
    for (int& y : x) {
      std::cin >> y;
    }
  }

  dp[0][0] = in[0][0] ? std::make_pair(0, 0) : std::make_pair(1, 1);
  for (int i = 1; i < n; ++i) {
    pint prev = dp[0][i - 1];
    dp[0][i] = in[0][i]
                   ? std::make_pair(0, 0)
                   : std::make_pair(prev.first + 1, prev.second + in[0][i - 1]);
  }
  for (int i = 1; i < n; ++i) {
    pint prev = dp[i - 1][0];
    dp[i][0] = in[i][0]
                   ? std::make_pair(0, 0)
                   : std::make_pair(prev.first + in[i - 1][0], prev.second + 1);
  }

  int max = dp[0][0].first;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (in[i][j]) {
        dp[i][j] = std::make_pair(0, 0);
        continue;
      }
      pint left = in[i][j - 1] ? std::make_pair(0, 1) : dp[i][j - 1];
      pint top = in[i - 1][j] ? std::make_pair(1, 0) : dp[i - 1][j];
      left.first++;
      top.second++;
      left.second = std::min(left.second, top.first);
      dp[i][j] = max_pair(left, top);
      max = std::max(rect_area(dp[i][j]), max);
    }
  }
  std::cout << max << "\n";
  return 0;
}
