# Creates a cpp file with the competetive programming template

WARNING="\e[31m[!]"
HINT="\e[33m[*]"
BOLD="\e[1m"

error_message="""\n
    $WARNING You must provide a file name\n
    $HINT Usage: ./cp_template [filename]\n
    $HINT Example: ./cp_template test"""

[ -z "$1" ] && echo -e $error_message && exit

script_dir=$(dirname "$0")
code_template=$(cat $script_dir/template.cpp) || (echo -e "$WARNING No cpp template file found in the root folder\n" && exit)

extension="cpp"
filename="$1"

pwd | cd

echo "$code_template" >"$filename.$extension"
echo >in
echo -e "\n$BOLD$HINT g++ -o sol $filename.cpp; ./sol < in\n"

code "$filename.$extension"

start .
