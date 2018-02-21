#include <stdio.h>
#define MAX_LEN 1000

void itoa(int n, char s[]);
void reverse(char s[], int len);

int main()
{
    char numstring[MAX_LEN];
    int num = 12345;
    itoa(num, numstring);
    printf("%s\n", numstring);
    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
    {
        n = -n;
    }
    i = 0;
    do 
    {
        s[i++] = n % 10 + '0';
    }
    while ((n /= 10) > 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s, 5);
}

void reverse(char s[], int len)
{
    int i;
    char temp;
    for(i=0; i < len/2; i++)
    {
        temp = s[len-i-1];
        s[len-i-1] = s[i];
        s[i] = temp;
    }
}