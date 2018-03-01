#include "calc.h"

/*
NOTE: I do not actually know anything serious about lexing as I write this;
Wikipedia says lexing is "is the process of converting a sequence of characters
(such as in a computer program or web page) into a sequence of tokens (strings
with an assigned and thus identified meaning)", which is what the functions in
this file do.
*/

// lex: get next operator or numeric operand
int lex(char s[])
{
    int i, c, c2, len;
    char symbol[MAX_TOKEN_SIZE];

    while(len = parse(symbol, MAX_TOKEN_SIZE))
    {
        if (isalpha(symbol[0]))
        {
            handle_alpha(symbol, len);
        }
        else if (isdigit(symbol[0]) || symbol[0] == '.')
        {
            return RAW;
        }
        else
        {
            return GARBAGE;
        }
    }
}

int handle_alpha(char operator[], int len)
{
    /*
    If we hit an alpha char, there are only two valid expressions:
    1) it's one character long, and therefore a variable
    2) it matches one of the supported mathematical functions,
    which are either 3 or 4 characters long. Anything else can
    be safely assumed to be garbage.
    */
    int i;

    if (len == 1)
    {
        return VAR;
    }

    if (len == 2 || len > 4)
    {
        return GARBAGE;
    }

    if (len == 3)
    {
        if (strncmp(operator, SIN_STR, len) == 0)
        {
            return SIN;
        }
        else if (strncmp(operator, COS_STR, len) == 0)
        {
            return COS;
        }
        else if (strncmp(operator, TAN_STR, len) == 0)
        {
            return TAN;
        }
        else if (strncmp(operator, POW_STR, len) == 0)
        {
            return POW;
        }
        else if (strncmp(operator, EXP_STR, len) == 0)
        {
            return EXP;
        }
    }
    if (len == 4)
    {
        if (strncmp(operator, ASIN_STR, len) == 0)
        {
            return ASIN;
        }
        else if (strncmp(operator, ACOS_STR, len) == 0)
        {
            return ACOS;
        }
        else if (strncmp(operator, ATAN_STR, len) == 0)
        {
            return ATAN;
        }
        else if (strncmp(operator, SQRT_STR, len) == 0)
        {
            return SQRT;
        }
        else if (strncmp(operator, FLOR_STR, len) == 0)
        {
            return FLOR;
        }
        else if (strncmp(operator, CIEL_STR, len) == 0)
        {
            return CIEL;
        }
    }

    // If we don't recognize the expression,
    // it's not supported.
    return GARBAGE;
}

/*
int handle_numeric(char operator[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {

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
}
*/