#include <stdio.h>

/* 
4-12: Adapt the ideas of printd to write a recursive version of itoa;
that is, convert an integer into a string by calling a recursive routine.

4-13: Write a recursive version of the function reverse (s), which
reverses the string s in place.
*/

#define MAX_LEN 100

int itoa(char arr[], int val, int latest, int len, int place);
void reverse(char arr[], int latest, int len);
void swap(char arr[], int x, int y);

int main()
{
    /*
    char test_str1[] = {"Joshua"};
    reverse(test_str1, 0, 5);
    printf("%s\n", test_str1);
    reverse(test_str1, 0, 5);
    printf("%s\n\n", test_str1);

    char test_str2[] = {"Josh"};
    reverse(test_str2, 0, 3);
    printf("%s\n", test_str2);
    reverse(test_str2, 0, 3);
    printf("%s\n\n", test_str2);
    */
    int len;
    int w = 1256;
    int x = 41236124;
    int y = -41236124;
    int z = 0;
    int q = 1;
    char string_number[MAX_LEN];

    len = itoa(string_number, w, 0, MAX_LEN, 1);
    reverse(string_number, 0, len-1);
    printf("%d == %s\n", w, string_number);

    len = itoa(string_number, x, 0, MAX_LEN, 1);
    reverse(string_number, 0, len-1);
    printf("%d == %s\n", x, string_number);

    len = itoa(string_number, y, 0, MAX_LEN, 1);
    reverse(string_number, 0, len-1);
    printf("%d == %s\n", y, string_number);

    len = itoa(string_number, z, 0, MAX_LEN, 1);
    reverse(string_number, 0, len-1);
    printf("%d == %s\n", z, string_number);

    len = itoa(string_number, q, 0, MAX_LEN, 1);
    reverse(string_number, 0, len-1);
    printf("%d == %s\n", q, string_number);

    return 0;
}

int itoa(char arr[], int val, int latest, int len, int place)
{
    /*
    General idea for computing each place of the string;
    assume we're itoa-ing 1256:

    printf("%d\n", (1256 % 10) / 1);            // prints 6
    printf("%d\n", (1256 % 100) / 10);          // prints 5
    printf("%d\n", (1256 % 1000) / 100);        // prints 2
    printf("%d\n", (1256 % 10000) / 1000);      // prints 1
    printf("%d\n", (1256 % 100000) / 10000);    // prints 0
    */

    int new_val;
    if (latest >= len)
    {
        printf("Error: Insufficient space to print string.\n");
        return -1;
    }
    
    if (val < 0)
    {

        val *= -1;
        arr[latest] = '-';
        return itoa(arr, val, latest+1, len, place);        
    }

    new_val = (val % (10 * place)) / place;
    if (new_val == 0)
    {
        // computation is finished
        return latest;
    }
    else
    {
        arr[latest] = new_val + '0';
        return itoa(arr, val, latest+1, len, place*10);
    }
}

void reverse(char arr[], int first, int last)
{
    if (first >= last)
    {
        return;
    }
    else 
    {
        swap(arr, first, last);
        reverse(arr, first+1, last-1);
    }
}

void swap(char arr[], int x, int y)
{
    char temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
