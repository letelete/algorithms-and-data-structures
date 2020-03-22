#include <bits/stdc++.h>

template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}

int maximum_subarray_problem(std::vector<int>& arr) {
  if (arr.empty()) return 0;
  if (arr.size() == 1) return arr[0];

  int cur, maximum;
  cur = maximum = arr[0];

  for (int i = 1; i < arr.size(); ++i) {
    cur = max(arr[i], arr[i] + maximum);
    maximum = max(maximum, cur);
  }

  return maximum;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> in(n);
  for (int& i : in) std::cin >> i;
  std::cout << maximum_subarray_problem(in) << "\n";
  return 0;
}