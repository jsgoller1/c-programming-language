#include "calc.h"

int sp = 0;
double values[MAX_STACK_SIZE];

// push() - push f onto value stack
void push(double f)
{
    if (sp < MAX_STACK_SIZE)
    {
        values[sp++] = f;
    }
    else
    {
        printf("Error; stack full - can't push %g\n", f);
    }
}

// pop: pop and return top value from stack; if the values are variables,
// dereference them and then return them.
double pop()
{
    if (sp > 0)
    {
        return values[--sp];
    }
    else{
        printf("Error: stack empty\n");
        return 0.0;
    }
}

// peek: reveal the top element of the stack without decrementing sp
double peek()
{
    if (sp == 0)
    {
        printf("Error, stack empty; returning 0.\n");
        return 0;
    }
    return values[sp-1];
}

// duplicate_top: instructions were unclear, but assuming that 
// this means add another element equal to the top element.
void duplicate_top()
{
    double top;
    top = pop();
    push(top);
    push(top);
}

// swap_top: switch the top two elements of the stack
void swap_top()
{
    double elem1, elem2;
    elem1 = pop();
    elem2 = pop();

    push(elem1);
    push(elem2);
}

