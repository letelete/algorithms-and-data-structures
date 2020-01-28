class Solution {
 public:
  struct index {
    int value = -1;
  };

  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, index> counters;
    for (int cur_index = 0; cur_index < nums.size(); ++cur_index) {
      int cur_number = nums[cur_index];
      int counter_index = counters[target - cur_number].value;
      if (counter_index != -1) {
        return std::vector<int>{{counter_index, cur_index}};
      }
      counters[cur_number] = index{cur_index};
    }
    return std::vector<int>();
  }
};