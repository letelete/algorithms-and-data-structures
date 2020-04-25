# Prints the command to compile and run a cpp file

WARNING="\e[31m[!]"
HINT="\e[33m[*]"
BOLD="\e[1m"

error_message="""\n
    $WARNING You must provide a file name\n
    $HINT Usage: ./runcpp [filename]"""

[ -z "$1" ] && echo -e $error_message && exit

echo -e "\n$BOLD$HINT g++ $1.cpp -std=c++11 -O2 -Wall -o sol; ./sol < in\n"
