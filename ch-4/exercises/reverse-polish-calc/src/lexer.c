#include <calc.h>

/*
NOTE: I do not actually know anything serious about lexing as I write this;
Wikipedia says lexing is "is the process of converting a sequence of characters
(such as in a computer program or web page) into a sequence of tokens (strings
with an assigned and thus identified meaning)", which is what the functions in
this file do.
*/

// lex: get next operator or numeric operand
int lex(char symbol[], int token_len)
{
    int len;

    while((len = parse(symbol, token_len)))
    {
        if (len == -1)
        {
            return EXIT;
        }
        if (is_operator(symbol))
        {
            return handle_operator(symbol);
        }

        if (isalpha(symbol[0]))
        {
            return handle_alpha(symbol, len);
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

    // Loop breaks on display.
    return DISPLAY;
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
    }

    // If we don't recognize the expression,
    // it's not supported.
    return GARBAGE;
}

int is_operator(char oper[])
{
    return ((oper[0] == '+') ||  (oper[0] == '-') ||  (oper[0] == '/') ||  (oper[0] == '*') ||  (oper[0] == '%') ||  (oper[0] == '='));
}

int handle_operator(char operator[])
{
    switch(operator[0])
    {
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        case '%':
            return MOD;
        case '=':
            return ASSIGN;            
        default:
            return GARBAGE;                            
    }
}