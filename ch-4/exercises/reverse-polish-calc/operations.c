#include "calc.h"

void add(double val1[], double val2[])
{
    //printf("+: %f (type: %f), %f (type: %f),\n", val1[0], val1[1], val2[0], val2[1]);
    if (val1[1] == VAR)
    {
        dereference(val1);
    }
    if (val2[1] == VAR)
    {
        dereference(val2);
    }
    val1[0] = val1[0] + val2[0];
    val1[1] = RAW;
    push(val1);
}

void subtract(double val1[], double val2[])
{
    //printf("-: %f (type: %f), %f (type: %f),\n", val1[0], val1[1], val2[0], val2[1]);
    if (val1[1] == VAR)
    {
        dereference(val1);
    }
    if (val2[1] == VAR)
    {
        dereference(val2);
    }
    val1[0] = val1[0] - val2[0];
    val1[1] = RAW;
    push(val1);
}

void multiply(double val1[], double val2[])
{
    //printf("*: %f (type: %f), %f (type: %f),\n", val1[0], val1[1], val2[0], val2[1]);
    if (val1[1] == VAR)
    {
        dereference(val1);
    }
    if (val2[1] == VAR)
    {
        dereference(val2);
    }
    val1[0] = val1[0] * val2[0];
    val1[1] = RAW;
    push(val1);
}

void divide(double val1[], double val2[])
{
    //printf("/: %f (type: %f), %f (type: %f),\n", val1[0], val1[1], val2[0], val2[1]);
    if (val1[1] == VAR)
    {
        dereference(val1);
    }
    if (val2[1] == VAR)
    {
        dereference(val2);
    }
    if (val2[0] == 0.0)
    {
        printf("Error: division by zero.\n");
        return;
    }
    val1[0] = val1[0] / val2[0];
    val1[1] = RAW;
    push(val1);
}

void modulus(double val1[], double val2[])
{
    //printf("mod: %f (type: %f), %f (type: %f),\n", val1[0], val1[1], val2[0], val2[1]);
    if (val1[1] == VAR)
    {
        dereference(val1);
    }
    if (val2[1] == VAR)
    {
        dereference(val2);
    }
    if (val2[0] == 0.0)
    {
        printf("Error: modulo by zero.\n");
        return;
    }

    val1[0] = (int)val1[0] % (int)val2[0];
    val1[1] = RAW;
    push(val1);
}

void sin(double val1[])
{
    if (val1[1] == VAR)
    {
        dereference(val1);
    }

    // do stuff
}

void cos(double val1[])
{
    if (val1[1] == VAR)
    {
        dereference(val1);
    }

    // do stuff
}

void tan(double val1[])
{
    if (val1[1] == VAR)
    {
        dereference(val1);
    }

    // do stuff
}

void pow(double val1[], double val2[])
{
    if (val1[1] == VAR)
    {
        dereference(val1);
    }
    if (val2[1] == VAR)
    {
        dereference(val2);
    }

    // do stuff
}

void exp(double val1[])
{
    if (val1[1] == VAR)
    {
        dereference(val1);
    }

    // do stuff
}

void sqrt(double val1[])
{
    if (val1[1] == VAR)
    {
        dereference(val1);
    }

    // do stuff
}