#include <stdio.h>

// test the differences between using single and double quotes

int main()
{
    int a, b, c, d;
    a = (b = 200); 
    d = c = 100;
    printf("%d %d\n", a, b); 
    printf("%d %d\n", d, c); 
    return 0;
}