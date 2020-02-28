# Creates a C++ template for competetive programming tasks
# inside of specified directory under given name

if [ -z "$1" ] || [ -z "$2" ]; then
    echo [!] All arguments must be satisfied
    echo [*] Usage: oi.sh [destination] [name]
    echo [*] Example: oi.sh /d/___programming/oi awesometask
else
    extension="cpp"
    filename="$2.$extension"

    cd $1

    echo """
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
    
    return 0;
}
        """ >"$filename"

    code $filename
fi
