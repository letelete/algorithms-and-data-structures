class Solution {
 public:
  // Time: O(n) | Space: O(1)
  int _findPeakElement(std::vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] > nums[i + 1]) return i;
    }
    return nums.size() - 1;
  }

  // Time O(logn) | Space: O(1)
  int findPeakElement(std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[mid + 1]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};