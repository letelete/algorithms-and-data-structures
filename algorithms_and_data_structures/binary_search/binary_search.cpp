#include <bits/stdc++.h>

class Theory {
 private:
  std::vector<int> arr;

 public:
  Theory(std::vector<int> &arr) { this->arr = arr; }

  // 1) Contains (True or False)
  bool contains(int num) {
    if (arr.empty()) return false;

    int left, right, mid;
    left = 0;
    right = arr.size() - 1;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (arr[mid] == num) {
        return true;
      } else if (arr[mid] > num) {
        right = --mid;
      } else {
        left = ++mid;
      }
    }

    return false;
  }

  // 2) Index of first occurrence of a key
  int first_occurence_index(int num) {
    if (arr.empty()) return -1;

    int left, right, mid, result;
    left = 0;
    right = arr.size() - 1;
    result = -1;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (arr[mid] == num) {
        result = mid;
        right = --mid;
      } else if (arr[mid] > num) {
        right = --mid;
      } else {
        left = ++mid;
      }
    }

    return result;
  }

  // 3) Index of last occurrence of a key
  int last_occurence_index(int num) {
    if (arr.empty()) return -1;

    int left, right, mid, result;
    left = 0;
    right = arr.size() - 1;
    result = -1;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (arr[mid] == num) {
        result = mid;
        left = ++mid;
      } else if (arr[mid] > num) {
        right = --mid;
      } else {
        left = ++mid;
      }
    }

    return result;
  }

  // 4) Index of least element greater than key
  int least_greater_index(int num) {
    if (arr.size() <= 1) return -1;

    int left, right, mid, result;
    left = 0;
    right = arr.size() - 1;
    result = -1;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (arr[mid] == num) {
        left = ++mid;
      } else if (arr[mid] > num) {
        result = mid;
        right = --mid;
      } else {
        left = ++mid;
      }
    }

    return result;
  }

  // 5) Index of greatest element less than key
  int greatest_least_index(int num) {
    if (arr.size() <= 1) return -1;

    int left, right, mid, result;
    left = 0;
    right = arr.size() - 1;
    result = -1;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (arr[mid] == num) {
        right = --mid;
      } else if (arr[mid] > num) {
        right = --mid;
      } else {
        result = mid;
        left = ++mid;
      }
    }

    return result;
  }
};

/*
Find first and last positions of an element in a sorted array
Given a sorted array with possibly duplicate elements, the task is to find
indexes of first and last occurrences of an element x in the given array.

Example:
Input: arr{{1, 3, 5, 5, 5, 5 ,67, 123, 125}}
x = 5
Output: {2, 5}
*/
class FirstAndLast {
 private:
  int first_occurence_index(std::vector<int> &arr, int num, int left) {
    int index = -1, right = arr.size() - 1, mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (arr[mid] == num) {
        index = mid;
        right = --mid;
      } else if (arr[mid] > num) {
        right = --mid;
      } else {
        left = ++mid;
      }
    }
    return index;
  }

  int last_occurence_index(std::vector<int> &arr, int num, int left) {
    int index = -1, right = arr.size() - 1, mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (arr[mid] == num) {
        index = mid;
        left = ++mid;
      } else if (arr[mid] > num) {
        right = --mid;
      } else {
        left = ++mid;
      }
    }
    return index;
  }

 public:
  std::pair<int, int> solve(std::vector<int> &arr, int num) {
    if (arr.empty()) return {-1, -1};

    int first_index = first_occurence_index(arr, num, 0);
    if (first_index == -1) return {-1, -1};

    int last_index = last_occurence_index(arr, num, first_index);

    return {first_index, last_index};
  }
};

int main() {
  // The given array is sorted.
  std::vector<int> arr{{1, 2, 3, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9, 10}};
  Theory theory = Theory(arr);

  // 1)
  std::cout << "2) Should be true: " << theory.contains(5) << "\n";

  // 2)
  std::cout << "2) Should equals 3: " << theory.first_occurence_index(4)
            << "\n";

  // 3)
  std::cout << "3) Should equals 12: " << theory.last_occurence_index(8)
            << "\n";

  // 4)
  std::cout << "4) Should equals 8: " << theory.least_greater_index(5) << "\n";

  // 5)
  std::cout << "5) Should equals 0: " << theory.greatest_least_index(2) << "\n";

  // First and last
  FirstAndLast first_and_last = FirstAndLast();
  auto range = first_and_last.solve(arr, 5);
  std::cout << "Task 1: Should be {5, 7}: {" << range.first << ", "
            << range.second << "}\n";
}
