class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int predicted_sum = 0;
    int predicted_sum_iterator = 0;
    int actual_sum = 0;
    for (const int& n : nums) {
      predicted_sum += ++predicted_sum_iterator;
      actual_sum += n;
    }
    return predicted_sum - actual_sum;
  }
};