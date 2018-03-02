#include <calc.h>

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

    // catch edge case where whitespace check gets the first character
    // but it wasn't a whitespace
    if (c != ' ' || c != '\t')
    {
        ungetch(c);
    }

    // if the very first char is \n, it means
    // the line is empty or the last call to parse
    // was at the end of a line, so we can safely
    // print the result of the expression.
    if (c == '\n')
    {
        getch(); // remove it from the buffer so we start clean next time we parse
        return 0;
    }

    i = 0;
    // parse all characters up to newline; if we encounter
    // a newline, push it back into the buffer, return
    // and let the next call to parse() end lexing.
    while (((c = getch()) != EOF) && !(c == ' ' || c == '\t' || c == '\n') && (i < s_size))
    {
        //printf("parsed: %c\n", c);
        s[i++] = c;
    }
    s[i] = '\0';

    if (c == EOF)
    {
        //printf("returning -1\n");        
        return -1;
    }
    else if (c == '\n')
    {
        // \n indicates we're at the end of the expression,
        // but we need to parse the last operator, so
        // push this back and then on the next parse
        // iteration we'll quit based on it.
        ungetch(c);
        return i;
    }
    else
    {
        //printf("returning %d for: %s\n", i, s);
        return i;
    }
}