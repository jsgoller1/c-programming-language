#include <stdio.h>

// What is the difference between using double and single quotes?

int main()
{
    // Int value of special character, here 10
    int a = '\n';
    printf("%d\n", a); 

    // Special character
    char b = '\n';
    printf("%c\n", b); 

    // Int value of the character, here 65
    int c = 'A';
    printf("%d\n", c); 

    // Actual character
    char d = 'A';
    printf("%c\n", d); 

    return 0;
}