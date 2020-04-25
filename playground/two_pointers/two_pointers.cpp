#include <bits/stdc++.h>

// Given the K and a sequence of n integers,
// find the longest subsequence [p;k], such that Sn < K,
// where Sn is the total sum of the subsequence.
int longest_sequence_with_lower_sum(std::vector<int> arr, int k) {
  if (arr.empty()) return 0;
  int longest = 0, window_sum = 0, left = 0, right = 0, window_size;
  while (right < arr.size()) {
    window_size = right - left + 1;
    window_sum += arr[right];
    if (window_sum >= k) {
      window_sum -= arr[left];
      ++left;
      ++window_size;
    } else if (window_size > longest) {
      longest = window_size;
    }

    ++right;
  }
  return longest;
}

int main() {
  std::vector<int> arr({1, 1, 1, 1, 4, 4, 4, 4});
  std::cout << longest_sequence_with_lower_sum(arr, 16) << "\n";

  return 0;
}