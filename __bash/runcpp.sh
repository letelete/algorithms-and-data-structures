# Prints the command to compile and run a cpp file

WARNING="\e[31m[!]"
HINT="\e[33m[*]"
BOLD="\e[1m"

error_message="""\n
    $WARNING You must provide a file name\n
    $HINT Usage: ./runcpp [filename]"""

[ -z "$1" ] && echo -e $error_message && exit

COMPILE_AND_RUN_WITH_INPUT_CMD="g++ $1.cpp -std=c++17 -Wshadow -Wall -o $1 ; ./$1 < in"
echo "$COMPILE_AND_RUN_WITH_INPUT_CMD" | clip.exe
echo -e "\n$HINT Run it with\n\n$COMPILE_AND_RUN_WITH_INPUT_CMD\n\n"
echo -e "\n$BOLD$HINT Command copied to clipboard\n"
