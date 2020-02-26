class Solution {
 public:
  int longestCommonSubsequence(string str1, string str2) {
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1));
    for (int i = 0; i <= str1.length(); ++i) {
      for (int j = 0; j <= str2.length(); ++j) {
        if (!i || !j) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
          if (str1[i - 1] == str2[j - 1]) {
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
          }
        }
      }
    }
    return dp.back().back();
  }
};