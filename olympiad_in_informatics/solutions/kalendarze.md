# [Kalendarze](https://szkopul.edu.pl/problemset/problem/LWpMcXylQBa6wHzcJ6U7axzK/site/?key=statement)

#### OIG stage II

#### Memory limit 32 MB

---

#### Score 100/100

### Complexity

#### Time: O(nlogn), where n - queries amount

#### Space: O(m + k), where m - bananit lengt, k - arbuzan length

---

```C++
#include <bits/stdc++.h>

namespace cp {
void optimize_io() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);
}

template <typename T>
using v = std::vector<T>;

typedef std::string str;
}  // namespace cp

using namespace cp;

#define ARBUZAN_ID 'A'
#define BANANIT_ID 'B'

int arbuzan_length, bananit_length;
v<int> arbuzan_months, bananit_months;

struct date {
  int day, month;
};

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

date translate_into_day_and_month(date query_date, char tribe_id) {
  v<int>& origin = tribe_id == ARBUZAN_ID ? arbuzan_months : bananit_months;
  v<int>& target = tribe_id == ARBUZAN_ID ? bananit_months : arbuzan_months;

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
```
