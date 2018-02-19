#include <stdio.h>

// Does the binary representation of 0x80000000 + 0x00000001 change
// depending on the type each is declared as?

int main() 
{
    unsigned int a = 0x80000000;
    unsigned int b = 0x00000001;

    signed int c = 0x80000000;
    signed int d = 0x00000001;

    // 0x80000001 = unsigned 2147483649, signed -2147483647
    printf("0x%x = unsigned %u, signed %d\n", a+b, a+b, a+b);

    // 0x80000001 = signed -2147483647, unsigned 2147483649
    printf("0x%x = signed %d, unsigned %u\n", c+d, c+d, c+d);

    // Note that in C, 0x80000000 + 0x00000001 = 0x80000001 always,
    // but the value associated with 0x80000001 depends on the type. 
    return 0;
}