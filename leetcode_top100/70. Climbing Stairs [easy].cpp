// https://leetcode.com/problems/climbing-stairs/

class Solution {
 public:
  int climbStairs(int stairs_amount) {
    std::vector<int> stair_steps(stairs_amount + 1);
    stair_steps[0] = stair_steps[1] = 1;
    for (int i = 2; i <= stairs_amount; ++i) {
      stair_steps[i] = stair_steps[i - 1] + stair_steps[i - 2];
    }
    return stair_steps[stairs_amount];
  }
};