#include "calc.h"

// getop: get next operator or numeric operand
int getop(char s[])
{
    int i, c;

    while (((s[0] = c = getch()) == ' ') || c == '\t' )
    {
        // no op; get all characters until a space/tab/newline is hit
    }
    s[1] = '\0';
    if (isalpha(c))
    {
        printf("%c is alpha, dereferencing.\n", c);
        sprintf(s, "%g", dereference(c));
        return NUMBER;
    }
    if (!isdigit(c) && c != '.')
    {
        return c; // if not a number or floating point
    }

    i = 0;
    if (isdigit(c)) // collect integer part
    {
        while(isdigit(s[++i] = c = getch()))
        {
            // no-op
        }
    }
    if (c == '.') // collect fractional part
    {
        while(isdigit(s[++i] = c = getch()))
        {
            // no-op
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;        
}

