# Creates an environment for participating in the codeforces contests

WARNING="\e[31m[!]"
HINT="\e[33m[*]"
BOLD="\e[1m"

error_message="""\n
    $WARNING All arguments must be satisfied\n
    $HINT Usage: ./cf [round-number] [div-id]\n
    $HINT Example: ./cf 1441 2\n"""

([ -z "$1" ] || [ -z "$2" ]) && echo -e $error_message && exit

script_dir=$(dirname "$0")
code_template=$(cat $script_dir/template.cpp) || (echo -e "$WARNING No cpp template file found in the root folder\n" && exit)

problem_set=(A B C D E F)
extension="cpp"
round_name="$1_div_$2"

pwd | cd
mkdir $round_name
cd "$round_name"

for problem in ${problem_set[*]}; do
    echo "$code_template" >"$problem.$extension"
done

echo >in
echo -e $(runcpp.sh A)

code ../$round_name

start .
