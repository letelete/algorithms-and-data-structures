class Solution {
 private:
  const char separator = '#';

  std::string make_every_substring_odd_length(std::string s) {
    std::string str = "";
    str.push_back(separator);
    for (const char& c : s) {
      str.push_back(c);
      str.push_back(separator);
    }
    return str;
  }

 public:
  std::string longestPalindrome(std::string str) {
    if (str.empty()) return str;

    str = make_every_substring_odd_length(str);

    int left, right, max_len = 1;
    int max_palindrome_start_index = 1;

    for (int center = 1; center < str.length() - 1; ++center) {
      left = center - 1;
      right = center + 1;

      while (left >= 0 && right < str.length() && str[left] == str[right]) {
        int palindrome_length = right - left + 1;
        if (palindrome_length > max_len) {
          max_len = palindrome_length;
          max_palindrome_start_index = left;
        }
        --left;
        ++right;
      }
    }

    str = str.substr(max_palindrome_start_index, max_len);

    std::string answer = "";
    for (const char& c : str) {
      if (c != separator) answer.push_back(c);
    }

    return answer;
  }
};