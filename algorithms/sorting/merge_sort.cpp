#include <bits/stdc++.h>

std::vector<int> merge_sort(const std::vector<int>& arr, int left, int right) {
  int current_arr_size = right - left + 1;
  if (current_arr_size <= 1) return std::vector<int>{{arr[right]}};

  int mid = left + (right - left) / 2;
  std::vector<int> a = merge_sort(arr, left, mid),
                   b = merge_sort(arr, mid + 1, right),
                   merged(current_arr_size);

  int a_index = 0, b_index = 0, index = 0;
  bool insert_a;
  while (a_index < a.size() || b_index < b.size()) {
    insert_a = (a_index < a.size()) &&
               (b_index >= b.size() || a[a_index] <= b[b_index]);
    merged[index] = insert_a ? a[a_index] : b[b_index];
    a_index += insert_a;
    b_index += !insert_a;
    ++index;
  }

  return merged;
}

int main() {
  std::vector<int> in{{-10, -8, -8, -7, 0, 0, 0, 0, 4, 6, 100, 404000}};
  std::vector<int> a = merge_sort(in, 0, in.size() - 1);
  for (const int& num : a) std::cout << num << " ";
  std::cout << "\n";
  return 0;
}