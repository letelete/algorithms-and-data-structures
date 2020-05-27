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
using _u_ll = unsigned long long;
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
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (a > b && d >= c) {
      std::cout << "-1\n";
      continue;
    }

    if (b >= a) {
      std::cout << b << "\n";
      continue;
    }

    _ll rest = a - b;
    _ll sleep_time = c - d;
    _ll add = (rest / sleep_time) + (rest % sleep_time != 0);
    std::cout << (_ll)((add * c) + b) << "\n";
  }

  return 0;
}
