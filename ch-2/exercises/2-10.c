#include <stdio.h>

// Rewrite lower() to convert strings of uppercase letters to
// lower, but without using if-else.

void mylower(char str[]);

int main()
{
    char name[] = {"JOSHUA"};
    mylower(name);
    printf("%s\n", name);

    char name2[] = {"bob"};
    mylower(name2);
    printf("%s\n", name2);

    char name3[] = {""};
    mylower(name3);
    printf("%s\n", name3);

    char name4[] = {"YoU ArE a GeNiUs!/#?"};
    mylower(name4);
    printf("%s\n", name4);

    return 0;
}

void mylower(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        ((str[i] >= 'A') && (str[i] <= 'Z')) ? (str[i] += 32) : str[i]; // second clause is a no-op.
        i++;
    }

}