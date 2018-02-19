#include <stdio.h>

int rand();
void srand(unsigned int seed);

unsigned long int next = 1;

int main()
{
    srand(5);
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    return 0;
}

 // rand: return pesudo-random int on 0..32767
int rand() 
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

// srand: set seed for rand()
void srand(unsigned int seed)
{
    next = seed;
}