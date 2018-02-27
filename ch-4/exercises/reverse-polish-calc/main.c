#include "calc.h"

// Reverse Polish calculator
int main()
{
    int type;
    double op2, op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop()); // commutative; pop() order is irrelevant
                break;
            case '*':
                push(pop() * pop()); // commutative; pop() order is irrelevant
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                {
                    push(pop() / op2);
                }
                else 
                {
                    printf("Error: div by zero");
                }
               break;
            case '%':
                op2 = pop();
                op1 = pop();
                push((int)op1 % (int)op2);
                break;
            case '=':
                // in the expression A 5 =, A is pushed first
                assign();
                break;            
            case '\n':
                printf("\t%.8f\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
