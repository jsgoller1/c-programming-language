#include <stdio.h>

// count characters in input, ver. 1

int power(int m, int n);

// power(); raise base to the nth power
int power(int base, int n){
    int p;
    for (p = 1; n > 0; n--) {
        p = p * base;
    }
    return p;
}

int main()
{
    int i;
    for (i = 2; i < 10; i++)
        printf("%d, %d, %d\n", i, power(i, 2), power(i, 5));
}