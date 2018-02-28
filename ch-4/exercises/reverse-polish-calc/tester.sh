#!/bin/bash

gcc -std=c99 -I ch-4/exercises/reverse-polish-calc/ ch-4/exercises/reverse-polish-calc/*.c -o ./calculator

function test_expression() {
   echo $1 | tee /dev/tty | ./calculator
}

# basic operators
## 3
test_expression "42.0 666.0 +"
## 1
test_expression "3 2 -"
## 2
test_expression "4 2 /"
## 36
#test_expression "6 6 *"
## 0
test_expression "6 6 %"
## Prints "OK", result is unchanged
test_expression "5 A ="



# compound expressions
## 24
#test_expression "1 2 + 3 5 + *"

# negatives
## -1
#test_expression "3 4 -"
## -5
#test_expression "5 3 4 - / "
## -10
#test_expression "5 3 5 - * "
## 3
#test_expression "5 3 5 - + "

# malformed input
## "Error: stack empty"
#test_expression ""
## "Error: unknown command" (for each letter, then "Error: stack empty")
#test_expression "asdasf"
## Invalid, result is unchanged
#test_expression "A 5 ="

rm ./calculator