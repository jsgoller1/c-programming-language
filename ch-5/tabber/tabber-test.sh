#!/bin/bash

function valg(){
  valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42 $1
}

./bin/tabber
printf "a         b" | valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42  ./bin/tabber -b entab
printf "a\t\tb" | valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42 ./bin/tabber -b detab
printf "a         b" | valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42 ./bin/tabber -b detab -l 0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75
printf "a\t\tb" | valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42 ./bin/tabber -b entab -l 0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75
printf "a          b" | valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42 ./bin/tabber -b entab -m 5+10
printf "a\t\tb" | valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42 ./bin/tabber -b detab -m 5+10

# -m and -l are exclusive, so this should return 255
valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42 ./bin/tabber -b detab -m 10+5 -l 10 15 20
if [ $? == 255 ]; then
  exit 0;
else
  exit 1;
fi
