class Solution {
 private:
  void permutation(std::vector<std::string>& res, std::string& s, int left) {
    if (left >= s.size()) {
      res.push_back(s);
      return;
    }
    bool perform_size_permutation = std::isalpha(s[left]);
    if (perform_size_permutation) {
      s[left] = std::toupper(s[left]);
      permutation(res, s, left + 1);
      s[left] = std::tolower(s[left]);
    }
    permutation(res, s, left + 1);
  }

 public:
  std::vector<std::string> letterCasePermutation(std::string S) {
    std::vector<std::string> res;
    permutation(res, S, 0);
    return res;
  }
};