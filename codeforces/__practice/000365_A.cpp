
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

    int n, k, count = 0;
    std::cin >> n >> k;
    while (n--) {
        str s;
        std::cin >> s;
        int greater = 0;
        std::unordered_set<int> seen;
        for (const char& c : s) {
            int digit = c - '0';
            if (digit <= k) seen.insert(digit);
        }
        count += (seen.size() == k + 1);
    }

    std::cout << count << "\n";

    return 0;
}
