
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

    int r1, r2, c1, c2, d1, d2;
    std::cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    int mina = std::min(std::min(r1, c1), d1);
    for (int a = 1; a < mina; ++a) {
        int d = d1 - a;
        int c = r2 - d;
        int b = c2 - d;
        std::unordered_set<int> eq{{a, b, c, d}};
        if (eq.size() < 4) continue;
        if (a >= 10 || b >= 10 || c >= 10 || d >= 10) continue;
        if (a + b != r1) continue;
        if (c + d != r2) continue;
        if (a + c != c1) continue;
        if (b + c != d2) continue;
        std::cout << a << " " << b << "\n"
                  << c << " " << d << "\n";
        return 0;
    }

    std::cout << "-1\n";

    return 0;
}
