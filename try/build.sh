path=$1
g++ -o build/${path%.*} $1 -std=c++20 -Wall -Wextra -Werror -Wpedantic -pedantic -pedantic-errors
