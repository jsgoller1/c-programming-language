#include <calc.h>

char buf[PARSE_BUFFER_SIZE]; // buffer for ungetch
int buffered = false;
int bufval; // this answers 4-8
int bufp = 0;

int getch()
{
    // uncomment for 4-8
    /*
    if (buffered == true > 0)
    {
        buffered = false;
        return bufval;
    }
    else
    {
        return getchar();
    }
    */

    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    // uncomment for 4-8
    /*
    buffered = true;
    bufval = c;
    */

    if (bufp >= PARSE_BUFFER_SIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

void ungets(char s[], int len)
{
    int i;

    for (i = 0; i < len && s[len] != '0'; i++)
    {
        ungetch(s[i]);
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
        s[i++] = c;
    }
    s[i] = '\0';

    if (c == EOF)
    {
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
        return i;
    }
}