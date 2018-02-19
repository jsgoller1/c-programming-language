#include <stdio.h>

// Does the binary representation of 0x80000000 + 0x00000001 change
// depending on the type each is declared as?

int main() 
{
    unsigned int a = 0x80000000;
    unsigned int b = 0x00000001;

    signed int c = 0x80000000;
    signed int d = 0x00000001;

    printf("0x%x = unsigned %u, signed %d\n", a+b, a+b, a+b);
    printf("0x%x = signed %d, unsigned %u\n", c+d, c+d, c+d);

    return 0;
}