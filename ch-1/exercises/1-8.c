#include <stdio.h>

// Write a program to count blanks, tabs, and newlines.

int main()
{
    int c, count;

    while ((c = getchar()) != EOF)
        switch(c) {
            case ' ':
                count++;
                break;
            case '\t':
                count++;
                break;
            case '\n':
                count++;
                break;
        }
    printf("%d\n", count);
    return 0;
}