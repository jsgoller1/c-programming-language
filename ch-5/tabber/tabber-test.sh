#!/bin/bash

./bin/tabber
printf "a         b" | ./bin/tabber -b entab
printf "a\t\tb" | ./bin/tabber -b detab
printf "a         b" | ./bin/tabber -b detab -l 0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75
printf "a\t\tb" | ./bin/tabber -b entab -l 0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75
printf "a          b" | ./bin/tabber -b entab -m 5+10
printf "a\t\tb" | ./bin/tabber -b detab -m 5+10

# -m and -l are exclusive, so this should return 255
./bin/tabber -b detab -m 10+5 -l 10 15 20
if [ $? == 255 ]; then
  exit 0;
else
  exit 1;
fi
