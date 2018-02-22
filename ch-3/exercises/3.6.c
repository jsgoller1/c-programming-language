#include <stdio.h>
#define MAX_LEN 1000
#define WORD_SIZE 4

/*
Write a version of itoa that accepts three arguments instead of
two. The third argument is a minimum field width; the converted number must
be padded with blanks on the left if necessary to make it wide enough.
*/

void itoa(int val, char s[], int pad);
void reverse(char s[], int len);

int main()
{

    char numstring[MAX_LEN];
    int num = 0; // 0
    itoa(num, numstring, 9);
    printf("%s == %d\n", numstring, num);

    num = 10; // 0
    itoa(num, numstring, 9);
    printf("%s == %d\n", numstring, num);

    num = 1000000; // 0
    itoa(num, numstring, 9);
    printf("%s == %d\n", numstring, num);

    num = 1000000000; // 0
    itoa(num, numstring, 9);
    printf("%s == %d\n", numstring, num);

    num = 0x7FFFFFFF; // 0
    itoa(num, numstring, 9);
    printf("%s == %d\n", numstring, num);

    return 0;
}

void itoa(int n, char s[], int pad)
{
    int i, is_negative;
    unsigned val;
    i = 0;

    // If the value is negative, multiply by
    // -1 and store the result as an unsigned int.
    is_negative = (n < 0);
    is_negative ? (val = n * -1) : (val = n);

    do
    {
        s[i++] = val % 10 + '0';
    }
    while ((val /= 10) > 0);
    if (is_negative)
    {
        s[i++] = '-';
    }

    // Doesn't execute if we exceed padding
    while (i < pad)
    {
      s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s, i);
}

void reverse(char s[], int len)
{
    int i;
    char temp;
    for (i=0; i < len/2; i++)
    {
        temp = s[len - i - 1];
        s[len-i-1] = s[i];
        s[i] = temp;
    }
}