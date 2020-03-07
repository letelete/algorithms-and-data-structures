
class Solution {
 public:
  int coinChange(vector<int>& coins, int k) {
    vector<int> dp(k + 1, k + 1);
    dp[0] = 0;
    for (int i = 1; i <= k; ++i) {
      for (const int& coin : coins) {
        if (i >= coin) dp[i] = std::min(dp[i - coin] + 1, dp[i]);
      }
    }
    return dp[k] > k ? -1 : dp[k];
  }
};