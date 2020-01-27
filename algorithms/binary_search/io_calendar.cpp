#include <bits/stdc++.h>

/**
 * Zadanie Kalendarze (kal)
 * - OIG Stage II. Memory limit: 32 MB.
 *
 https://szkopul.edu.pl/problemset/problem/LWpMcXylQBa6wHzcJ6U7axzK/site/?key=statement
 *
 * Score: 100 / 100
 */

namespace cp {
void optimize_io() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);
}

template <typename T>
using v = std::vector<T>;

template <typename K, typename V>
using umap = std::unordered_map<K, V>;

template <class T>
T min(T a, T b) {
  return a > b ? b : a;
}

template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}

typedef std::string str;

template <class T>
T pow(T a, unsigned b = 2) {
  if (b == 0) return 1;
  unsigned temp = pow(a, b / 2);
  if (b % 2 == 0) return temp * temp;
  return a * temp * temp;
}
}  // namespace cp

using namespace cp;

#define ARBUZAN_ID 'A'
#define BANANIT_ID 'B'

int arbuzan_length, bananit_length;
v<int> arbuzan_months, bananit_months;

int index_of_least_or_equal_days(const v<int>& target, int total_days) {
  int left, right, mid, answer;
  left = 0;
  right = target.size() - 1;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (target[mid] == total_days) {
      return mid;
    } else if (target[mid] > total_days) {
      answer = mid;
      right = --mid;
    } else {
      left = ++mid;
    }
  }
  return answer;
}

struct date {
  int day, month;
};

date translate_into_day_and_month(date query_date, char tribe_id) {
  std::vector<int>& origin =
      tribe_id == ARBUZAN_ID ? arbuzan_months : bananit_months;
  std::vector<int>& target =
      tribe_id == ARBUZAN_ID ? bananit_months : arbuzan_months;

  int total_days = query_date.day;
  if (query_date.month >= 2) total_days += origin[query_date.month - 2];

  int nearest_month_index = index_of_least_or_equal_days(target, total_days);
  if (nearest_month_index >= 1) {
    total_days -= target[nearest_month_index - 1];
  }

  return {total_days, nearest_month_index + 1};
}

int main() {
  optimize_io();

  std::cin >> arbuzan_length >> bananit_length;
  arbuzan_months = v<int>(arbuzan_length);
  bananit_months = v<int>(bananit_length);

  for (int i = 0, days_of_month; i < arbuzan_length; ++i) {
    std::cin >> days_of_month;
    if (i >= 1) days_of_month += arbuzan_months[i - 1];
    arbuzan_months[i] = days_of_month;
  }

  for (int i = 0, days_of_month; i < bananit_length; ++i) {
    std::cin >> days_of_month;
    if (i >= 1) days_of_month += bananit_months[i - 1];
    bananit_months[i] = days_of_month;
  }

  int queries_length;
  std::cin >> queries_length;
  while (queries_length--) {
    date query_date;
    char tribe_id;
    std::cin >> query_date.day >> query_date.month >> tribe_id;
    date translated_date = translate_into_day_and_month(query_date, tribe_id);
    std::cout << translated_date.day << " " << translated_date.month << "\n";
  }

  return 0;
}