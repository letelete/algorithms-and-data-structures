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

using namespace cp;

int MAX_N = (int)1e6;
_v<int> tree(MAX_N + 1, 0);

int lsb(int of) { return of & -of; }

_ll prefix_sum(int index) {
  _ll sum = 0;
  while (index) {
    sum += tree[index];
    index -= lsb(index);
  }
  return sum;
}

void add_at(int index, int value) {
  while (index < (int)tree.size()) {
    tree[index] += value;
    index += lsb(index);
  }
}

void remove_nth(int nth) {
  int lo = 1, hi = MAX_N;
  while (lo < hi) {
    int mid = lo + ((hi - lo) / 2);
    int mid_value = prefix_sum(mid);
    if (mid_value < nth) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  add_at(lo, -1);
}

int alive_index() {
  int lo = 1, hi = MAX_N;
  while (lo < hi) {
    int mid = lo + ((hi - lo) / 2);
    int mid_value = prefix_sum(mid);
    if (mid_value <= 0) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main() {
  _optimize;
  int n, q;
  std::cin >> n >> q;
  while (n--) {
    int x;
    std::cin >> x;
    tree[x]++;
  }

  for (int i = 1; i < (int)tree.size(); ++i) {
    int parent = i + lsb(i);
    if (parent < (int)tree.size()) {
      tree[parent] += tree[i];
    }
  }

  while (q--) {
    int x;
    std::cin >> x;
    if (x < 0) {
      remove_nth(abs(x));
    } else {
      add_at(x, 1);
    }
  }

  int ans = alive_index();
  std::cout << (prefix_sum(ans) > 0 ? ans : 0) << "\n";

  return 0;
}
