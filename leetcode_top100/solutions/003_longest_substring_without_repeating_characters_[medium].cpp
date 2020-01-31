class Solution {
 public:
  struct index {
    int value = -1;
  };

  int lengthOfLongestSubstring(std::string str) {
    if (str.length() <= 1) return str.length();

    int l = 0, r = 0, longest = 0;
    std::unordered_map<char, index> seen;

    while (r < str.size()) {
      int& char_index = seen[str[r]].value;
      if (char_index < l) {
        int window_length = r - l + 1;
        if (window_length > longest) longest = window_length;
        char_index = r;
        ++r;
      } else {
        l = char_index + 1;
      }
    }
    return longest;
  }
};