
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

    int n, top, left, right;
    std::cin >> n >> top;

    while (n--) {
        std::cin >> left >> right;
        int next_top = 7 - top;
        if (left == top || right == top || left == next_top || right == next_top) {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";

    return 0;
}
