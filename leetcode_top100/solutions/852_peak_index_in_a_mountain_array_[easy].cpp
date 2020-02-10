class Solution {
 public:
  int peakIndexInMountainArray(std::vector<int>& A) {
    int left = 0, right = A.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (A[mid] > A[mid + 1]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};