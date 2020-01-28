# Creates new day's directory with template files in given AoC year path

CPP_TEMPLATE="""#include <bits/stdc++.h>

void optimize_io() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);
}

template <typename T>
using v = std::vector<T>;

template <typename K, typename V>
using umap = std::unordered_map<K, V>;

template <class T>
T min(T a, T b) {
  return a > b ? b : a;
}

template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}

template <class T>
T pow(T a, unsigned b = 2) {
  if (b == 0) return 1;
  unsigned temp = pow(a, b / 2);
  if (b % 2 == 0) return temp * temp;
  return a * temp * temp;
}

int main() {
  optimize_io();

  return 0;
}"""

if [ -z $1 ]
then
    echo No required argument given: AoC year
    echo Usage: "./hello.sh <AoC year> <task name [optional]>"
    echo Example: "./hello.sh 2019 rocket_launcher"
else
    if [ ! -d $1 ]; 
    then
      echo Directory \"$1\" does not exist
    else
      cd $1
      DAY="$(find . -type d -printf x | wc -c)"
      DAY_PATH="day_$DAY"
      mkdir "$DAY_PATH"
      cd "$DAY_PATH"
      echo > in
      CPP_FILENAME=$2
      if [ -z $2 ]
      then
        CPP_FILENAME="solution"
      fi
      echo "$CPP_TEMPLATE" > "$CPP_FILENAME".cpp
      echo -e "\nQuick copy-paste formula to run your solution:"
      echo "cd $1/$DAY_PATH; g++ -o $CPP_FILENAME ./$CPP_FILENAME.cpp; ./$CPP_FILENAME"
      echo -e "\nHappy coding :)"
    fi
fi
