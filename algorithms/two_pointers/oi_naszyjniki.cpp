#include <bits/stdc++.h>

namespace cp {
void optimize_io() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);
}

template <typename T>
using v = std::vector<T>;

template <typename K, typename V>
using umap = std::unordered_map<K, V>;

template <class T>
T min(T a, T b) {
  return a > b ? b : a;
}

template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}

typedef std::string str;

template <class T>
T pow(T a, unsigned b = 2) {
  if (b == 0) return 1;
  unsigned temp = pow(a, b / 2);
  if (b % 2 == 0) return temp * temp;
  return a * temp * temp;
}
}  // namespace cp

using namespace cp;

int necklaces_amount;

const std::set<char> vowels{{'a', 'e', 'i', 'o', 'u', 'y'}};

bool is_bright(char c) { return vowels.count(c); }

bool is_small(char c) { return c >= 'a' && c <= 'z'; }

struct coral {
  str name;
  int value;
};

struct necklace {
  int length = -1;
  coral coral_pattern;
  void print() { std::cout << length << " " << coral_pattern.name << "\n"; }
};

coral from_char(char c) {
  bool c_bright = is_bright(c);
  bool c_small = is_small(c);
  coral result;
  if (c_bright) {
    result = c_small ? coral{"jasne", 2} : coral{"JASNE", 4};
  } else {
    result = c_small ? coral{"ciemne", 1} : coral{"CIEMNE", 3};
  }
  return result;
}

void solve(str pattern) {
  int left = 1, right = 1;
  coral prev_coral = from_char(pattern[0]), cur_coral;
  necklace min_lace{INT_MAX}, max_lace{INT_MIN};
  int window_size;

  str first_perfect_pattern = "";
  first_perfect_pattern += pattern[0];

  bool create_perfect_pattern = true;

  auto perform_check = [&window_size, &min_lace, &max_lace, &prev_coral]() {
    if (window_size >= 2) {
      if (window_size < min_lace.length ||
          (window_size == min_lace.length &&
           prev_coral.value > min_lace.coral_pattern.value)) {
        min_lace = {window_size, prev_coral};
      } else if (window_size > max_lace.length ||
                 (window_size == max_lace.length &&
                  prev_coral.value > max_lace.coral_pattern.value)) {
        max_lace = {window_size, prev_coral};
      }
    }
  };

  while (right < pattern.length()) {
    window_size = right - left + 1;
    char cur_char = pattern[right];
    cur_coral = from_char(cur_char);

    if (prev_coral.value != cur_coral.value) {
      --window_size;
      if (create_perfect_pattern) {
        pattern += first_perfect_pattern;
        create_perfect_pattern = false;
      }
      perform_check();
      left = right;
    }

    if (create_perfect_pattern) first_perfect_pattern += cur_char;
    prev_coral = cur_coral;
    ++right;
  }

  if (max_lace.length > pattern.length()) {
    int length = pattern.length();
    min_lace = max_lace = necklace{length, from_char(pattern[0])};
  } else if (left != right) {
    perform_check();
  }

  max_lace.print();
  min_lace.print();
}

int main() {
  std::cin >> necklaces_amount;
  str necklace;
  while (necklaces_amount--) {
    std::cin >> necklace;
    solve(necklace);
  }
  return 0;
}