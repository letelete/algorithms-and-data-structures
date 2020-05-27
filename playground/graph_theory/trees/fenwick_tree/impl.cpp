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

class FenwickTree {
 public:
  FenwickTree(const _v<int>& values) { _build_tree(values); }

  void print() {
    for (unsigned i = 1; i < _tree.size(); ++i) {
      std::cout << "Index of " << i << " equals to " << _tree[i] << "\n";
    }
  }

  /**
   * Updates the point at given index with given value.
   *
   * Time: O(log(n)), where n = _tree.size()
   */
  void update_point(unsigned index, int value) {
    assert(index > 0 && index < _tree.size());
    int diff = value - _tree[index];
    while (index < _tree.size()) {
      _tree[index] += diff;
      index = _upper_cascade_index(index);
    }
  }

  /**
   * Returns the prefix sum of given range inclusively.
   *
   * Time: O(log(n)), where n = _tree.size()
   */
  _ll range_query(unsigned from, unsigned to) {
    assert(from > 0);
    assert(to < _tree.size());
    assert(from <= to);
    _ll inclusive_to_sum = _prefix_sum(to);
    _ll exclusive_from_sum = _prefix_sum(from - 1);
    return inclusive_to_sum - exclusive_from_sum;
  }

  /**
   * Returns a value at given point
   */
  int point_query(unsigned index) {
    assert(index > 0 && index < _tree.size());
    return _prefix_sum(index);
  }

 private:
  _v<int> _tree;

  /**
   * Returns the least significant bit of given index as decimal value.
   *
   * The least significant bit (LSB) determines the range of responsibility that
   * cell has to the cells below itself.
   *
   * Time: O(n), where n = sizeof(T) * CHAR_BIT
   */
  template <typename T>
  T _LSB(T index) {
    T distance = 0;
    while (!(1 & index >> distance++))
      ;
    return 1 << (distance - 1);
  }

  /**
   * Builds the 1-indexed Fenwick tree from given values in relative order.
   *
   * Time: O(n), where n = values.size()
   */
  void _build_tree(const _v<int>& values) {
    _tree = _v<int>(values.size() + 1, 0);
    int values_size = values.size();
    for (int index = 1; index <= values_size; ++index) {
      _tree[index] += values[index - 1];
      int parent = index + _LSB(index);
      if (parent <= values_size) {
        _tree[parent] += _tree[index];
      }
    }
  }
  /**
   * Returns the least smaller index out of the responsibility range of the
   * given index.
   */
  unsigned _lower_cascade_index(unsigned index) { return index - _LSB(index); }

  /**
   * Returns the least higher index out of the responsibility range of the
   * given index.
   */
  unsigned _upper_cascade_index(unsigned index) { return index + _LSB(index); }

  /**
   * Returns the prefix sum of the inclusive range <1; index>.
   */
  _ll _prefix_sum(unsigned index) {
    _ll sum = 0;
    while (index) {
      sum += _tree[index];
      index = _lower_cascade_index(index);
    }
    return sum;
  }
};

int main() {
  _optimize;

  _v<int> arr{{3, 4, -2, 7, 3, 11, 5, -8, -9, 2, 4, -8}};
  FenwickTree* ft = new FenwickTree(arr);
  ft->print();

  std::cout << "\nRange query test\n";
  std::cout << "Should be: 19 and is: " << ft->range_query(3, 6) << "\n";

  std::cout << "\nThe current sum is: " << ft->range_query(11, 12) << "\n";
  ft->update_point(1, 10);
  std::cout << "After updating the values by 8 it's " << ft->range_query(11, 12)
            << "\n";
  ft->print();

  std::cout << "\nPoint query for index 2: " << ft->point_query(2) << "\n";

  return 0;
}
