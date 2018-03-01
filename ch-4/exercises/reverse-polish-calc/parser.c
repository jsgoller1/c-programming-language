#include "calc.h"

char buf[PARSE_BUFFER_SIZE]; // buffer for ungetch
int bufp = 0;

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= PARSE_BUFFER_SIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

int parse(char s[], int s_size)
{
    int i, c;

    // no op; skip over all leading whitespace and tabs
    while (((c = getch()) == ' ') || c == '\t')
    {

    }

    i = 0;
    // parse all characters up to newline;
    while (((c = getch()) != EOF) && (i < s_size))
    {
        if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
        {
            s[i++] = c;
        }
    }
    s[i] = '\0';

    if (c == EOF)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}