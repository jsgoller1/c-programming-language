#include <stdio.h>

// Ex. 1-12 - write a program that prints every word of input on its own line
int main()
{
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            putchar('\n');
        else {
            putchar(c);
        }
    }
    return 0;
}