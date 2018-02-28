#include "calc.h"

// getop: get next operator or numeric operand
int getop(char s[])
{
    int i, c, c2;

    while (((s[0] = c = getch()) == ' ') || c == '\t' )
    {
        // no op; get all characters until a space/tab/newline is hit
    }
    s[1] = '\0';

    // if we hit an alpha char, the only valid expression is if it's
    // followed by a whitespace; if not, parse the remaining garbage input,
    // save it in the string, and return it so we can report an invalid
    // expression to the user.
    if (isalpha(c))
    {
        c2 = getch();
        if (c2 != ' ')
        {
            s[1] = c2;
            i = 2;
            while((c2 = getch()) != '\n')
            {
                s[i++] = c2;
            }
            s[i] = '\0';
            return GARBAGE;
        }
        return VAR;
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

    return RAW;        
}

