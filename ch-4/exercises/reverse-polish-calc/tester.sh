#!/bin/bash

FILE=$1

gcc -std=c99 ch-4/exercises/$FILE -o ./calculator

# basic operators
## 3
echo "1.0 2.0 +" | tee /dev/tty | ./calculator
## 1
echo "3 2 -" | tee /dev/tty | ./calculator
## 2
echo "4 2 /" | tee /dev/tty | ./calculator
## 36
echo "6 6 *" | tee /dev/tty | ./calculator
## 0
echo "6 6 %" | tee /dev/tty | ./calculator


# compound expressions
## 24
echo "1 2 + 3 5 + *" | tee /dev/tty | ./calculator

# negatives
## -1
echo "3 4 -" | tee /dev/tty | ./calculator
## -5
echo "5 3 4 - / " | tee /dev/tty | ./calculator
## -10
echo "5 3 5 - * " | tee /dev/tty | ./calculator
## 3
echo "5 3 5 - + " | tee /dev/tty | ./calculator

# malformed input
## "Error: stack empty"
echo "" | tee /dev/tty | ./calculator
## "Error: unknown command" (for each letter, then "Error: stack empty")
echo "asdasf" | tee /dev/tty | ./calculator

rm ./calculator