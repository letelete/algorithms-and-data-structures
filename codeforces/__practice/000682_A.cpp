
#include <bits/stdc++.h>
typedef long long int i64;
template <typename T>
using v = std::vector<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
typedef std::string str;
typedef std::vector<int> vint;
typedef std::vector<std::string> vstr;
typedef std::vector<char> vchar;
typedef std::pair<int, int> pint;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    v<i64> aux(10, 0);
    i64 n, m, count = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) ++aux[i % 5];
    for (int i = 1; i <= m; i++) count += aux[(5 - i % 5) % 5];
    std::cout << count << "\n";

    return 0;
}
