#include <bits/stdc++.h>

namespace cp {
#define _optimize   \
  std::cin.tie(0);  \
  std::cout.tie(0); \
  std::ios::sync_with_stdio(0);

#define _v std::vector
#define _q std::queue
#define _pq std::priority_queue
#define _uset std::unordered_set
#define _set std::set
#define _map std::map
#define _umap std::unordered_map

#define _pair std::pair
#define _makepair std::make_pair
#define _maketuple std::make_tuple

#define _cin std::cin
#define _cout std::cout

using _ll = long long int;
using _ull = unsigned long long;
using _str = std::string;
};  // namespace cp

namespace debug {
// using Time = std::chrono::high_resolution_clock;
// auto seed = Time::now().time_since_epoch().count();
// std::mt19937 gen = std::mt19937(seed);
// template <typename T>
// T random(T from, T to) {
//   return std::uniform_int_distribution<T>{from, to}(gen);
// }

template <typename T>
void watch(T var, std::string name = "#") {
  std::cout << "Watching: " << name << " | " << var << "\n";
}
};  // namespace debug

using namespace cp;

int main() {
  _optimize;

  int t;
  std::cin >> t;
  while (t--) {
    _str in;
    std::cin >> in;

    int one = 0, two = 0, three = 0;
    int best_len = INT_MAX;
    _q<char> bucket;

    auto all_in = [&one, &two, &three]() { return one && two && three; };
    auto increment = [&one, &two, &three](char c, int by) {
      if (c == '1') {
        one += by;
      } else if (c == '2') {
        two += by;
      } else {
        three += by;
      }
    };

    for (int i = 0; i < (int)in.length(); ++i) {
      increment(in[i], 1);
      bucket.push(in[i]);
      if (!all_in()) continue;
      while (true) {
        increment(bucket.front(), -1);
        if (all_in()) {
          bucket.pop();
        } else {
          increment(bucket.front(), 1);
          break;
        }
      }
      if (all_in()) best_len = std::min(best_len, (int)bucket.size());
    }

    std::cout << ((best_len > (int)in.length()) ? 0 : best_len) << "\n";
  }

  return 0;
}
