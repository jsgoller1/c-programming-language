#include <ctype.h>
#include <stdio.h>

int atoi(char s[]);

int main()
{
    printf("%d\n", atoi("53241"));
    return 0;
}

// atoi: convert s to integer, v2
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++){} // skip whitespace

    // K&R do this and I dislike it
    // sign = (s[i] == '-') ? -1 : 1;
    (s[i] == '-') ? (sign = -1) : (sign = 1);

    if (s[i] == '+' || s[i] == '-') // skip sign
    {
        i++;
    }

    for (n = 0; isdigit(s[i]); i++)
    {
        n = 10 * n + (s[i] - '0');
    }
    return sign * n;
}