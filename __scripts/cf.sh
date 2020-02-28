# Creates an environment for participating in the codeforces contests

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]; then
    echo [!] All arguments must be satisfied
    echo [*] Usage: ./cf [destination] [round-number] [div-id]
    echo [*] Example: ./cf /d/___programming/cp 1441 2
else
    problem_set=(A B C D E F)
    extension="cpp"
    round_name="$2_div_$3"

    cd $1
    mkdir $round_name
    cd $round_name

    for problem in ${problem_set[*]}; do
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
        """ >"$problem.$extension"
    done

    cd ..
    code $round_name
fi
