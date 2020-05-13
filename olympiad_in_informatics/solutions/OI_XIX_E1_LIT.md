# [OI_XIX_E1_LIT](https://szkopul.edu.pl/problemset/problem/V1PYHlhJQGTY6KR5ODoTTYU4/site/?key=statement)

#### OI Stage I

#### Memory limit 32 MB

---

#### Score 100/100

### Complexity

#### Time: O(n)

#### Space: O(n)

---

```C++
#include <bits/stdc++.h>

#define fastIO      \
  std::cin.tie(0);  \
  std::cout.tie(0); \
  std::ios::sync_with_stdio(0);

template <typename T>
using v = std::vector<T>;
template <typename T>
using q = std::queue<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
typedef long long int i64;
typedef std::string str;
typedef std::vector<int> vint;

i64 merge(vint& arr, int l, int mid, int r) {
  i64 inv = 0;
  int lo = l, hi = mid + 1;
  vint aux;
  while ((lo <= mid) && (hi <= r)) {
    if (arr[lo] <= arr[hi]) {
      aux.push_back(arr[lo++]);
    } else {
      inv += (mid + 1) - lo;
      aux.push_back(arr[hi++]);
    }
  }
  while (lo <= mid) aux.push_back(arr[lo++]);
  while (hi <= r) aux.push_back(arr[hi++]);
  for (int i = l, k = 0; i <= r; ++i) arr[i] = aux[k++];
  return inv;
}

i64 merge_sort(vint& arr, int l, int r) {
  if (l >= r) return 0;

  i64 inv = 0;
  int mid = l + ((r - l) / 2);

  inv += merge_sort(arr, l, mid);
  inv += merge_sort(arr, mid + 1, r);
  inv += merge(arr, l, mid, r);

  return inv;
}

i64 count_inversions(vint& inv) { return merge_sort(inv, 0, inv.size() - 1); }

int main() {
  fastIO;

  int N;
  str J, M;

  std::cin >> N >> J >> M;

  umap<char, q<int>> char_index;
  vint inversion(N);

  for (int i = 0; i < N; ++i) char_index[M[i]].push(i);

  for (int i = 0; i < N; ++i) {
    auto& nearest = char_index[J[i]];
    inversion[i] = nearest.front();
    nearest.pop();
  }

  std::cout << count_inversions(inversion) << "\n";

  return 0;
}
```
