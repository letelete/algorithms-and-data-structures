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

const char delimiter = '|';
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    str scale, left;
    std::cin >> scale >> left;

    bool deli = false;
    v<char> lv, rv;
    for (const char& c : scale) {
        if (c == delimiter) {
            deli = true;
            continue;
        }
        if (deli) rv.push_back(c);
        else
            lv.push_back(c);
    }
    for (const char& c : left) {
        if (rv.size() < lv.size()) rv.push_back(c);
        else
            lv.push_back(c);
    }
    if (lv.size() == rv.size()) {
        for (const char& c : lv) std::cout << c;
        std::cout << "|";
        for (const char& c : rv) std::cout << c;
    } else {
        std::cout << "Impossible";
    }
    std::cout << "\n";

    return 0;
}