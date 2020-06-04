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

  int sum = 17;
  _v<int> arr{{1, 5, 8, 2, 10, 2, 5, 7}};
  std::sort(arr.begin(), arr.end());

  _v<_v<int>> solutions;

  for (int i = 0; i < (int)arr.size() - 2; ++i) {
    if (i && arr[i] == arr[i - 1]) continue;
    int required_sum = sum - arr[i];
    int lo = i + 1, hi = arr.size() - 1;
    auto next_lo = [&lo, &hi, &arr]() {
      ++lo;
      while (lo < hi && arr[lo] == arr[lo - 1]) ++lo;
    };
    auto next_hi = [&lo, &hi, &arr]() {
      --hi;
      while (lo < hi && hi < (int)arr.size() - 1 && arr[hi] == arr[hi + 1])
        --hi;
    };
    while (lo < hi) {
      int curr_sum = arr[lo] + arr[hi];
      if (curr_sum == required_sum) {
        solutions.push_back({{i, lo, hi}});
        next_lo();
        next_hi();
      } else if (curr_sum > required_sum) {
        next_hi();
      } else {
        next_lo();
      }
    }
  }

  auto pretty_print = [&arr, &sum](_v<int> answer) {
    std::cout << "[";
    for (int j = 0; j < (int)answer.size(); ++j) {
      std::cout << answer[j] << "(" << arr[answer[j]] << ")"
                << (j == (int)answer.size() - 1 ? "]" : ", ");
    }
    std::cout << " = " << sum << "\n";
  };

  if (solutions.empty()) {
    std::cout << "Not possible\n";
  } else {
    for (const auto& solution : solutions) {
      pretty_print(solution);
    }
  }

  return 0;
}
