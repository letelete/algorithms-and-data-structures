#include <bits/stdc++.h>

// Relations
// c -> [a,b]
// a -> [c];
// b -> [c];
std::unordered_map<char, std::unordered_set<char>> rel;

const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
std::unordered_map<char, bool> used;

std::string solve(const std::string& pass) {
  if (pass.size() <= 1) return pass;

  for (int i = 0; i < pass.size() - 1; ++i) {
    char cur = pass[i], next = pass[i + 1];
    used[cur] = used[next] = true;
    if (rel[cur].count(next) || rel[next].count(cur)) {
      continue;
    } else {
      rel[cur].insert(next);
    }
    if (rel[cur].size() > 2) return "";
  }
  return "";
}

void output_answer(const std::string& pass) {
  std::string ans = solve(pass);
  if (ans.empty()) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
    for (const auto& pair : used) {
      if (!pair.second) std::cout << pair.first;
    }
    std::cout << "\n";
  }
}

int main() {
  for (const char& letter : alphabet) used[letter] = false;
  int t;
  std::cin >> t;
  std::string pass;
  while (t--) {
    std::cin >> pass;
    output_answer(pass);
  }
  for (const auto& pair : rel) {
    std::cout << pair.first << ": [ ";
    for (const auto& a : pair.second) std::cout << a << " ";
    std::cout << " ]\n";
  }
  return 0;
}