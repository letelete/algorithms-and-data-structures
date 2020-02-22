# [Minusy](https://szkopul.edu.pl/problemset/problem/POAyCWzUB990_g4_MA4GF9Jw/site/?key=statement)

#### OI stage III

#### Memory limit 256 MB

---

#### Score 100/100

### Complexity

#### Time: O(n)

#### Space: O(n)

---

```C++
#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int input_length;
  std::cin >> input_length;

  char op;
  bool bracket_open;
  std::string result = "";

  for (int i = 0; i < (input_length - 1); i++) {
    std::cin >> op;
    if (op == '-') {
      if (bracket_open) {
        result += ")-";
        bracket_open = false;
      } else {
        result += "-";
      }
    } else {
      if (bracket_open) {
        result += "-";
      } else {
        result += "(-";
        bracket_open = true;
      }
    }
  }

  if (bracket_open) {
    result += ")";
  }

  std::cout << result << "\n";

  return 0;
}
```
