
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

    int n;
    str dirs;
    std::cin >> n >> dirs;
    int min_diff = INT_MAX;
    int last_r_i = -1;
    for (int i = 0, x; i < n; ++i) {
        std::cin >> x;
        char cur = dirs[i];
        if (cur == 'R') {
            last_r_i = x;
        } else if (last_r_i != -1) {
            int mid = last_r_i + ((x - last_r_i) / 2);
            int diff = mid - last_r_i;
            min_diff = std::min(diff, min_diff);
        }
    }

    std::cout << (min_diff != INT_MAX ? min_diff : -1) << "\n";
    
    return 0;
}
        
