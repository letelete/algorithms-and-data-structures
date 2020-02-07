class Solution {
 private:
  int search_for_first_positive(std::vector<int>& nums) {
    if (nums.front() >= 0) return 0;
    if (nums.back() < 0) return nums.size() - 1;

    const int min_positive = 0;
    int left = 0, right = nums.size() - 1;
    int index = 0;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] >= min_positive) {
        index = mid;
        right = mid - 1;
      } else if (nums[left] < min_positive) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return index;
  }

 public:
  std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> sorted_square_arr(nums.size());

    int right = search_for_first_positive(nums), left = right - 1;
    int index = 0;

    while (index < nums.size()) {
      int left_square = INT_MAX, right_square = INT_MAX;
      if (left >= 0) left_square = nums[left] * nums[left];
      if (right < nums.size()) right_square = nums[right] * nums[right];
      if (left_square <= right_square) {
        sorted_square_arr[index] = left_square;
        --left;
      } else {
        sorted_square_arr[index] = right_square;
        ++right;
      }
      ++index;
    }
    return sorted_square_arr;
  }
};