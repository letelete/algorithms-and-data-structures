
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

bool is_power_of_two(int number) { return number && (number & (number - 1)); }

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  // NOT
  // 00001010
  int x = 10;
  // 00001001
  int y = 9;

  // x:   00001010
  // y:   00001000
  // AND: 00001000
  // OR:  00001010
  // XOR: 00000010

  //
  std::cout << "x, y: " << std::bitset<8>(x) << " " << std::bitset<8>(y)
            << "\n";
  std::cout << "AND: " << std::bitset<8>(x & y) << "\n";
  std::cout << "OR: " << std::bitset<8>(x | y) << "\n";
  std::cout << "XOR: " << std::bitset<8>(x ^ y) << "\n";
  std::cout << "\n";

  i64 k = 1LL << 21;
  std::cout << is_power_of_two(0) << "\n";
  std::cout << is_power_of_two(1) << "\n";
  std::cout << is_power_of_two(2) << "\n";
  std::cout << is_power_of_two(3) << "\n";
  std::cout << is_power_of_two(4) << "\n";

  unsigned long long largenum = (1ULL << 63) + ((1ULL << 63) - 1);
  std::cout << largenum << "\n";

  std::cout << "Checking number x=" << x << " bits\n";
  std::cout << "Binary representation x=" << std::bitset<8>(x) << "\n";
  for (int i = 0; i < 8; ++i) {
    std::cout << "Is bit " << (i + 1) << " on? "
              << ((1 & (x >> i)) ? "YES" : "NO") << "\n";
  }

  auto subsetsum = [](vint nums, int S) {
    for (int mask = 0; mask <= (1 << nums.size()) - 1; ++mask) {
      int permutation_sum = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (1 & (mask >> i)) permutation_sum += nums[i];
      }
      if (permutation_sum == S) return true;
    }
    return false;
  };

  bool segment_exist = subsetsum(
      vint({2,   3,        4,     8,    10,   6,        19,     20,   10000,
            12,  12312424, 12323, 5151, 124,  24214214, 124124, 6326, 2353,
            787, 434,      33423, 6236, 2336, 32636,    33}),
      2);
  std::cout << "Segment exists? " << (segment_exist ? "YES" : "NO") << "\n";

  return 0;
}
