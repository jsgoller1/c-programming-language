#include <stdio.h>

// count characters in input, ver. 2

int main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc); // Note that this will count newlines as characters!
    return 0;
}