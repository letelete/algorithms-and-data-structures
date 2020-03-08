#include <bits/stdc++.h>
typedef long long int i64;
template <typename T>
using v = std::vector<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<std::string> vstr;
typedef std::vector<char> vchar;
typedef std::pair<int, int> pint;

/**
 * Solved with editorials and help of /profile/iprakhar22 explanation:
 *
 * Let's calculate each bit in the answer separately. Suppose we want to know
 * the value of k-th (in 0-indexation) bit in the answer. Then we can notice
 * that we are only interested in bits from 0-th to k-th, which means that we
 * can take all numbers modulo 2k+1. After that, the sum of the two numbers
 * can't exceed 2k+2−2. k-th bit is 1 if and only if sum belongs to [2k;2k+1) or
 * [2k+1+2k;2k+2−2]. So, we have to count the number of pairs of numbers that
 * give a sum that belongs to these segments. Let's sort all numbers (taken by
 * modulo) and make a pass with two pointers or do binary searches for each
 * number.
 */

const int limit = 2e7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;
  vint a(n);
  for (int& x : a) std::cin >> x;

  int total = 0;

  int limit_bits_amount = 0;
  for (int i = 1; i <= limit; i <<= 1) ++limit_bits_amount;

  i64 answer = 0;
  for (int bit = 1; bit <= limit_bits_amount; ++bit) {
    vint b(n);
    for (int i = 0; i < n; ++i) b[i] = a[i] % (1 << (bit));
    std::sort(b.begin(), b.end());
    i64 x = 0;
    for (int i = 0; i < n; ++i) {
      vint::iterator start = b.begin() + i + 1;
      int p1 =
          std::lower_bound(start, b.end(), (1 << (bit - 1)) - b[i]) - b.begin();
      int p2 =
          std::lower_bound(start, b.end(), (1 << (bit)) - b[i]) - b.begin();
      x += p2 - p1;
      p1 = lower_bound(start, b.end(), (1 << (bit)) + (1 << (bit - 1)) - b[i]) -
           b.begin();
      x += n - p1;
    }
    answer += (x % 2) * 1LL * (1 << (bit - 1));
  }

  std::cout << answer << "\n";

  return 0;
}
