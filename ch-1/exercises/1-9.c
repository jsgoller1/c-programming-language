#include <stdio.h>

// Write a program to copy its input to its output, 
// replacing each string of one or more blanks with a single blank

int main()
{
    int c, count, was_space;

    while ((c = getchar()) != EOF){
        if (c == ' ') {
            was_space = 1;
        } 
        else 
        {
            if (was_space == 1) {
                putchar(' ');
                was_space = 0;
            }
            putchar(c);
        }
    }
    return 0;
}