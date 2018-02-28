#include "calc.h"

// operations.c
void add(double val1[], double val2[])
{
    printf("+: %f (type: %f), %f (type: %f),\n", val1[0], val1[1], val2[0], val2[1]);
}

void subtract(double val1[], double val2[])
{
    printf("-: %f (type: %f), %f (type: %f),\n", val1[0], val1[1], val2[0], val2[1]);
}

void multiply(double val1[], double val2[])
{
    printf("*: %f (type: %f), %f (type: %f),\n", val1[0], val1[1], val2[0], val2[1]);    
}

void divide(double val1[], double val2[])
{
    printf("/: %f (type: %f), %f (type: %f),\n", val1[0], val1[1], val2[0], val2[1]);    
}

void modulus(double val1[], double val2[])
{
    printf("mod: %f (type: %f), %f (type: %f),\n", val1[0], val1[1], val2[0], val2[1]);
}
