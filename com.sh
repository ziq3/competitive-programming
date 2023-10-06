filename=$1
basename=${filename%.cpp}

flags="g++ -std=c++11 $basename.cpp -o $filename -Wall -Wextra -Wunused-variable -pedantic -Wshadow -Wconversion -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fno-sanitize-recover"


echo $flags

$flags

val=$?

RED='\033[1;31m'
GREEN="\033[1;32m"
NC='\033[0m'

echo 

if [ $val == 0 ]
then
	echo -e "${GREEN}Compilation ${GREEN}finished ${GREEN}successfully${NC}"
	exit 0
else
	echo -e "${RED}Compilation ${RED}failed${NC}"
	exit 1
fi