DEFAULT_COLOR="\e[39m"
POSITIVE_COLOR="\e[92m"
WARNING_COLOR="\e[93m"
ERROR_COLOR="\e[91m"

SRC_PATH="src"
EXECUTABLE_NAME="knapsack_solver"
OUTPUT_FILENAME="results"

function print_as_error() {
    echo -e "$ERROR_COLOR $1 $DEFAULT_COLOR"
}

function print_as_warning() {
    echo -e "$WARNING_COLOR $1 $DEFAULT_COLOR"
}

function print_as_positive() {
    echo -e "$POSITIVE_COLOR $1 $DEFAULT_COLOR"
}

function abortOpeningTextEditor() {
    print_as_error "Couldn't preview an output file. Please do it manually by opening $OUTPUT_FILENAME in your text editor."
}

function useTextEditorAlternative() {
    print_as_warning "Couldn't preview results via the Visual Studio Code app. Opening via alternative instead."
    notepad $OUTPUT_FILENAME || abortOpeningTextEditor
}

cd $SRC_PATH && print_as_positive "Compiling C++ project..."
g++ *.cc -std=c++17 -O2 -Wall -o $EXECUTABLE_NAME
./$EXECUTABLE_NAME >$OUTPUT_FILENAME

rm $EXECUTABLE_NAME
mv $OUTPUT_FILENAME ..
cd ..

print_as_positive "Opening results..."
code $OUTPUT_FILENAME || useTextEditorAlternative
