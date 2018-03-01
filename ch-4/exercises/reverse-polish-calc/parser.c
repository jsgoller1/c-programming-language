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

    // if the very first char is \n, it means
    // the line is empty or the last call to parse
    // was at the end of a line, so we can safely
    // exit.
    if (c == '\n')
    {
        printf("Initial parse encountered newline, returning 0.\n");
        return 0;
    }

    i = 0;
    // parse all characters up to newline; if we encounter
    // a newline, push it back into the buffer, return
    // and let the next call to parse() end lexing.
    while (((c = getch()) != EOF) && (i < s_size))
    {
        printf("parsed: %c\n", c);
        if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
        {
            s[i++] = c;
        }
    }
    s[i] = '\0';

    if (c == '\n')
    {
        ungetch(c);
    }

    if (c == EOF)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}