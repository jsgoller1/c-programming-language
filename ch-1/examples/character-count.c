#include <stdio.h>

// count characters in input, ver. 1

int main()
{
    long nc = 0;
    while (getchar() != EOF)
        nc++;
    printf("%ld\n", nc); // Note that this will count newlines as characters!
    return 0;
}