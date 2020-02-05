class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2) return false;
        
        std::stack<char> seen;
        std::unordered_map<char, char> counters {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}};
        
        for (const char& bracket : s) {
            bool is_closing_bracket = counters[bracket] == '\0';
            if (is_closing_bracket) {
                if (seen.empty() || counters[seen.top()] != bracket) return false;
                seen.pop();
            } else {
                seen.push(bracket);
            }
        }
        
        return seen.empty();
    }
};