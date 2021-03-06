// Bottom up itterative way
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

// Top down using recursion (TLE on leetcode)
class Solution {
 public:
  string pop_last(std::string& str) {
    if (str.empty()) return str;
    return str.substr(0, str.length() - 1);
  }
  int longestCommonSubsequence(string a, string b) {
    if (a.empty() || b.empty()) return 0;
    if (a.back() == b.back())
      return 1 + longestCommonSubsequence(pop_last(a), pop_last(b));
    return std::max(longestCommonSubsequence(pop_last(a), b),
                    longestCommonSubsequence(a, pop_last(b)));
  }
};