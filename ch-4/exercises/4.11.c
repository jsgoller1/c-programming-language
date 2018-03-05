#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>

#define MAXOP 100 // max size for operand or operator
#define NUMBER '0'

static int c = ' ';

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);

// Reverse Polish calculator
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                c = ' ';                
                break;
            case '+':
                push(pop() + pop()); // commutative; pop() order is irrelevant
                c = ' ';                
                break;
            case '*':
                push(pop() * pop()); // commutative; pop() order is irrelevant
                c = ' ';
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                c = ' ';
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
                c = ' ';
               break;
            case '\n':
                printf("\t%.8g\n", pop());
                c = ' ';
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 // maximum depth of val stack

int sp = 0;
double val[MAXVAL];

// push() - push f onto value stack
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("Error; stack full - can't push %g\n", f);
    }
}

// pop: pop and return top value from stack
double pop()
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else{
        printf("Error: stack empty\n");
        return 0.0;
    }
}

// getop: get next operator or numeric operand
int getop(char s[])
{
    int i;
    extern int c;

    while (((s[0] = c) == ' ') || (c == '\t' ))
    {
        // no op; get all characters until a space/tab/newline is hit
        c = getchar(); 
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        return c; // if not a number or floating point
    }
    i = 0;
    if (isdigit(c)) // collect integer part
    {
        while(isdigit(s[++i] = c = getchar()))
        {
            // no-op
        }
    }
    if (c == '.') // collect fractional part
    {
        while(isdigit(s[++i] = c = getchar()))
        {
            // no-op
        }
    }
    s[i] = '\0';
    /*if (c != EOF)
    {
        ungetch(c);
    }
    */
    return NUMBER;        
}