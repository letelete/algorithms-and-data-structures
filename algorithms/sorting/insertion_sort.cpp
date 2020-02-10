#include <bits/stdc++.h>

struct BinaryInsertionSort {
  int search_for_insert_index(const std::vector<int>& nums, int bound) {
    int left = 0, right = bound - 1, index = bound;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == nums[bound]) {
        return mid;
      } else if (nums[mid] > nums[bound]) {
        index = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return index;
  }

  void sort(std::vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      int insert_index = search_for_insert_index(nums, i);
      int temp_i = i;
      while (temp_i > insert_index) {
        std::swap(nums[temp_i], nums[temp_i - 1]);
        --temp_i;
      }
    }
  }
};

struct VanillaInsertionSort {
  void sort(std::vector<int>& nums) {
    for (int i = 1, runner = i; i < nums.size(); runner = ++i) {
      while (runner && nums[runner - 1] > nums[runner]) {
        std::swap(nums[runner - 1], nums[runner]);
        --runner;
      }
    }
  }
};

int main() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::vector<int> in{{-10, -8, -8, -7, 0, 0, 0, 0, 4, 6, 100, 404000}};

  VanillaInsertionSort vanillaInsertionSort;
  BinaryInsertionSort binaryInsertionSort;

  std::shuffle(in.begin(), in.end(), std::default_random_engine(seed));
  vanillaInsertionSort.sort(in);
  std::vector<int> vanillaSortResults = in;

  std::shuffle(in.begin(), in.end(), std::default_random_engine(seed));
  binaryInsertionSort.sort(in);
  std::vector<int> binarySortResults = in;

  assert(vanillaSortResults == binarySortResults);
  std::cout << "ok\n";

  return 0;
}