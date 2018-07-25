#!/bin/bash

# char* x()
echo "In: x () * char"
echo "Expected:  char* x()"
printf "Actual: "
echo "x () * char" | ./bin/undecl | grep "char\* x()"
printf "\n"

# char x[]
echo "In: x [] char"
echo "Expected:  char x[]"
printf "Actual: "
echo "x [] char" | ./bin/undecl | grep "char x\[\]"
printf "\n"

# char (*x)()
# declare x as pointer to function returning char
echo "In: x * () char"
echo "Expected: char (*x)()"
printf "Actual: "
echo "x * () char" | ./bin/undecl | grep "char (\*x)()"
printf "\n"

# char (*(*x())[])()
# declare x as function returning pointer to array of pointer to function returning char
echo "In: x () * [] * () char"
echo "Expected: char (*(*x())[])()"
printf "Actual: "
echo "x () * [] * () char" | ./bin/undecl | grep "char (\*(\*x())\[\])()"
printf "\n"

# char** (*x)()
# declare x as pointer to function returning pointer to pointer to char
echo "In: x * () * * char"
echo "Expected:  char **(*x)()"
printf "Actual: "
echo "x * () * * char" | ./bin/undecl | grep "char \*\*(\*x)()"
printf "\n"
