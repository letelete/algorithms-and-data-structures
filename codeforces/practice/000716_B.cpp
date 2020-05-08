#include <bits/stdc++.h>

#pragma GCC target("popcnt")

#define fastIO      \
  std::cin.tie(0);  \
  std::cout.tie(0); \
  std::ios::sync_with_stdio(0);

template <typename T>
using v = std::vector<T>;
template <typename T>
using q = std::queue<T>;
template <typename T>
using pq = std::priority_queue<T>;
template <typename T>
using set = std::set<T>;
template <typename T>
using uset = std::unordered_set<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
template <typename K, typename V>
using map = std::map<K, V>;
template <typename T, typename K>
using pair = std::pair<T, K>;

typedef long long int i64;
typedef unsigned long long ui64;

typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<char> vchar;
typedef std::vector<std::string> vstr;
typedef std::pair<int, int> pint;

const char WILDCARD = '?';
const int UNUSED = -1;
const str NO_ANSWER = "-1";

str alpha;

unsigned lo = 0, hi = 0;
bool valid_window = false;
umap<char, int> last_index;
q<char> replace;

bool window_size_valid() { return (hi - lo) + 1 == alpha.size(); }

bool char_in_window(const char& next) {
  if (next == WILDCARD) return false;
  if (!last_index.count(next)) return false;
  if (last_index[next] == UNUSED) return false;
  return true;
}

str solve(str input) {
  if (input.length() < alpha.length()) return NO_ANSWER;

  while (hi < input.size()) {
    char next = input[hi];
    if (char_in_window(next)) {
      unsigned last_copy_index = last_index[next];
      while (lo <= last_copy_index) last_index[input[lo++]] = UNUSED;
    }
    last_index[next] = hi;
    if (window_size_valid()) {
      valid_window = true;
      break;
    }
    ++hi;
  }

  if (!valid_window) return NO_ANSWER;

  for (const auto& x : alpha) {
    if (last_index.count(x) && last_index[x] != UNUSED) continue;
    replace.push(x);
  }

  for (unsigned i = 0; i <= input.length(); ++i) {
    if (input[i] != WILDCARD) continue;
    if (i >= lo && i <= hi) {
      input[i] = replace.front();
      replace.pop();
    } else {
      input[i] = alpha[0];
    }
  }

  return input;
}

int main() {
  fastIO;

  str input;
  for (int i = 'A'; i <= 'Z'; ++i) {
    alpha.push_back((char)i);
  }

  std::cin >> input;
  std::cout << solve(input) << "\n";

  return 0;
}

/** ℹ Useful
 * __builtin_popcount/ll
 * __builtin_clz/ll
 * __builtin_ctz/ll
 */
