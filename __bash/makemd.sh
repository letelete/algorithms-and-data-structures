# Converts given code file into markdown format with format specified below

if [ -z "$1" ]; then
    echo "[!] All arguments must be satisfied"
    echo "[!] A relative file path must be specified"
    echo "[*] Usage: makemd.sh [relative file path] [task_url](optional)"
    echo "[*] Example: makemd.sh banknoty.cpp https://szkopul.edu.pl/problemset/problem/ucULQRwTgKsiCRWkf0t9GoqH/site/?key=statement"
else
    file="$1"
    abs_path="$PWD/$file"
    code=$(cat $file)
    md_content=md_template

    file_title=$(echo $file | cut -d '.' -f1)
    task_url="$2"

    echo """# [${file_title^}]($task_url)

---

### Complexity

#### Time: O(n)

#### Space: O(n)

---

\`\`\`C++
$code
\`\`\`
""" >"${file_title}.md"

    echo "Do you want to remove an original code file? (y/n)"
    while :; do
        read -n 1 -t 15 selection
        printf "\n"
        case $selection in
        y*) rm $file ;;

        \
            *) exit 0 ;;
        esac
    done
fi
