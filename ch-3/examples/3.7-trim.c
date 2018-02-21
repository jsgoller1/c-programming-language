#include <stdio.h>
#include <string.h>

int trim(char s[]);

int main()
{
    char badstring[] = {"Lots of trailing shit  \t\n"};
    trim(badstring);
    printf("%s\n", badstring);
    char badstring2[] = {"    "};
    trim(badstring2);
    printf("%s\n", badstring2);
    char badstring3[] = {""};
    trim(badstring3);
    printf("%s\n", badstring3);

    return 0;
}

int trim(char s[])
{
    int n;

    for (n = strlen(s)-1; n >= 0; n--)
    {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        {
            break;
        }
    }
    s[n+1] = '\0';
    return n;
}
