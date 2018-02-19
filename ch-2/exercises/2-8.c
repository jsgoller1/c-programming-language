#include <stdio.h>

// Write a function rotate(x,p) rotates x by n bits right.

unsigned rotate(int x, int n, int str_size);

int main()
{
    // 0b11010100 = 0xD4
    printf("%x\n", rotate(0b10100110, 3, 8));
    
    // 0b00000111 = 0x7 
    printf("%x\n", rotate(0b00111000, 3, 8));
    
    // 0x00, no effect.
    printf("%x\n", rotate(0, 3, 8));
    
    // 0xFF, no effect
    printf("%x\n", rotate(0b11111111, 3, 8));
    return 0;
}

unsigned rotate(int x, int n, int str_size) 
{
    // capture n lowest bits
    int lowest_mask = ~(~0 << n);
    int lowest = x & lowest_mask;

    // shift x by n to the right
    x = x >> n;

    // take n lowest bits and make them n highest bits
    int highest = lowest << (str_size - n);
    
    // combine
    return highest | x;
}