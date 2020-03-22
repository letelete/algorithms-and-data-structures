#include <bits/stdc++.h>

int main() {
  std::vector<int> nums{
      {3, 3, 3, 17, 44, 17, 3, 21, 21, 37, 55, 42, 42, 80, 13}};
  std::vector<int> scaled(nums.size());

  std::sort(nums.begin(), nums.end());

  int seen = nums[0] * (-1), indicator = -1;
  for (int i = 0; i < nums.size(); ++i) {
    if (seen != nums[i]) ++indicator;
    scaled[i] = indicator;
    seen = nums[i];
  }

  for (const int& otp : scaled) std::cout << otp << " ";

  return 0;
}
