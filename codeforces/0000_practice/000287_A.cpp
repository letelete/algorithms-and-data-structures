
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

const char black = '#';
const char white = '.';

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int n= 4;
    v<str> grid(n, str(n, black));

    for (int i = 0; i < n; ++i) {
        for (char& c : grid[i]) std::cin >> c;
    }

    for (int i = 0; i <= n - 2; ++i) {
        for (int j = i; j <= n - 2; ++j) {
            int b = 0,w = 0;
            for(int c = 0 ; c < 2; ++c) {   
                for(int r = 0; r < 2; ++r) {
                    if(grid[i + c][j + r] == black) b++;
                    else w++;
                }
            }
            int max = std::max(b, w);
            if (max >= 3) {
                std::cout << "YES\n";
                return 0;
            }
        }
    }

    std::cout << "NO\n";
    
    return 0;
}