#!/bin/bash

# char* x()
echo "x () * char" | ./bin/undecl | grep "char\* x()"

# char x[]
echo "x [] char" | ./bin/undecl | grep "char x\[\]"

# char (*x)()
# declare x as pointer to function returning char
echo "x * () char" | ./bin/undecl | grep "char (\*x)()"

# char (*(*x())[])()
# declare x as function returning pointer to array of pointer to function returning char
echo "x () * [] * () char" | ./bin/undecl | grep "char (\*(\*x())\[\])()"

# char** (*x)()
# declare x as pointer to function returning pointer to pointer to char
echo "x * () * * char" | ./bin/undecl | grep "char \*\*(\*x)()"
