#include <stdio.h>
#include <stdlib.h>

int htoi(char string[], int len);
int mypow(int base, int exp);

int main()
{
    // 344865
    char hex0[] = {"0x54321"};
    printf("%s = %d\n", hex0, htoi(hex0, 7));
    
    // 74565
    char hex1[] = {"0X12345"};
    printf("%s = %d\n", hex1, htoi(hex1, 7));

    // 0
    char hex2[] = {"0X0"};
    printf("%s = %d\n", hex2, htoi(hex2, 3));

    // ERROR: Invalid length for hex number.
    char hex3[] = {"0X"};
    printf("%s = %d\n", hex3, htoi(hex3, 2));
    
    // ERROR: Invalid length for hex number.
    char hex4[] = {""};
    printf("%s = %d\n", hex4, htoi(hex4, 0));

    // ERROR: Not a hex number
    char hex5[] = {"12345"}; 
    printf("%s = %d\n", hex5, htoi(hex5, 5));

    return 0;
}

int htoi(char string[], int len) 
{
    int val = 0;

    if (len < 3) 
    {
        printf("ERROR: Invalid length for hex number.\n");
        return -1;
    }

    if (string[0] != '0' || (string[1] != 'x' && string[1] != 'X'))
    {
        printf("ERROR: '%s' is not a hex number.\n", string);
        return -1;
    }

    int i, charval;
    for (i = len-1; i>1; i--)
    {
        if (string[i] >= '0' && string[i] <= '9')
        {
            charval = string[i] - '0';
        } else {
            switch (string[i]) 
            {
                case 'A':
                case 'a':
                    charval = 10;
                case 'B':
                case 'b':
                    charval = 11;
                case 'C':
                case 'c':
                    charval = 12;
                case 'D':
                case 'd':
                    charval = 13;
                case 'E':
                case 'e':
                    charval = 14;
                case 'F':
                case 'f':
                    charval = 15;                                                                                                    
            }
        }
        val += charval * mypow(16, (len-1)-i);
    }
    return val;
}

int mypow(int base, int exp) 
{
    if (exp == 0)
    {
        return 1;
    } else {
        return base * mypow(base, exp-1);
    }
}
