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
using Time = std::chrono::high_resolution_clock;
auto seed = Time::now().time_since_epoch().count();
std::mt19937 gen = std::mt19937(seed);
template <typename T>
T random(T from, T to) {
  return std::uniform_int_distribution<T>{from, to}(gen);
}

template <typename T>
void watch(T var, std::string name = "#") {
  std::cout << "Watching: " << name << " | " << var << "\n";
}
};  // namespace debug

using namespace cp;

class RMQ {
 public:
  RMQ(_v<int> input) { _build_st(input); };

  int query(int from, int to) {
    assert(from <= to);
    assert(from >= 0 && to < _N);
    int p = floor(log2(to - from + 1));
    int k = 1 << p;
    int left = _st[p][from];
    int right = _st[p][to - k + 1];
    return std::min(left, right);
  }

 private:
  _v<_v<int>> _st;
  int _N;
  int _P;

  void _build_st(_v<int> from) {
    _N = from.size();
    _P = floor(log2(_N));
    _st = _v<_v<int>>(_P + 1, _v<int>(_N));
    for (int i = 0; i < _N; ++i) _st[0][i] = from[i];

    for (int i = 1; i < _N; ++i) {
      for (int j = 0; j <= _N - (1 << i); ++j) {
        int left = _st[i - 1][j];
        int right = _st[i - 1][j + (1 << (i - 1))];
        _st[i][j] = std::min(left, right);
      }
    }
  }
};

class Test {
 public:
  Test(_v<int> input, RMQ* rmq) : _input(input), _rmq(rmq){};
  ~Test() { delete _rmq; }

  bool test_random_range() {
    int end = _input.size() - 1;
    int from = debug::random(0, end);
    int to = debug::random(from, end);

    int brute_ans = _brute_force(from, to);
    int rmq_ans = _rmq->query(from, to);

    std::cout << "Test #" << (++_test_count) << " ";

    if (brute_ans != rmq_ans) {
      std::cout << "\e[31m" << _err_msg(from, to, brute_ans, rmq_ans)
                << "\e[39m\n";
      return false;
    }

    std::cout << "\e[32mOK\e[39m\n";
    return true;
  }

 private:
  _v<int> _input;
  RMQ* _rmq;
  int _test_count = 0;

  _str _format_math_range(int from, int to) {
    std::stringstream msg;
    msg << "<" << from << "; " << to << ">";
    return msg.str();
  }

  _str _err_msg(int from, int to, int brute_ans, int rmq_ans) {
    std::stringstream msg;
    msg << "Answers in range " << _format_math_range(from, to) << " differ\n"
        << "Expected " << brute_ans << ", but got " << rmq_ans << "\n";
    return msg.str();
  }

  int _brute_force(int from, int to) {
    int min = INT_MAX;
    for (int i = from; i <= to; ++i) {
      min = std::min(_input[i], min);
    }
    return min;
  }
};

RMQ* rmq;
Test* test;

int main() {
  _optimize;

  int n;
  _v<int> input;
  while (std::cin >> n) input.push_back(n);

  rmq = new RMQ(input);
  test = new Test(input, rmq);

  while (test->test_random_range())
    ;

  return 0;
}
