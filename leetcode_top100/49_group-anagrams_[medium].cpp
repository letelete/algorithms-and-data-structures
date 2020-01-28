class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> output;
    unordered_map<string, vector<string>> seen;
    for (const string& str : strs) {
      string sorted = str;
      std::sort(sorted.begin(), sorted.end());
      seen[sorted].push_back(str);
    }
    for (const auto& seen_pair : seen) {
      output.push_back(seen_pair.second);
    }
    return output;
  }
};