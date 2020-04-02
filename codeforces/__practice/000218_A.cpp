
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

    int n, k;
    std::cin >> n >> k;
    vint p((2 * n) + 1);
    for (auto& x : p) std::cin >> x;
    for (int i = 2 * n; i > 0 && k; --i) {
        int low = p[i] - 1;
        if (p[i - 1] < low && p[i + 1] < low) {
            p[i]--;
            k--;
        }
    }
    for (const auto& x : p) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
