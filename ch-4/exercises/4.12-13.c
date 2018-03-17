#include <stdio.h>
#include <stdbool.h>

/*
4-12: Adapt the ideas of printd to write a recursive version of itoa;
that is, convert an integer into a string by calling a recursive routine.

4-13: Write a recursive version of the function reverse (s), which
reverses the string s in place.
*/

#define MAX_LEN 100

int itoa(char arr[], int len, int val);
int convert(char arr[], int len, int val, int place, int index);
void reverse(char arr[], int first, int last);
void swap(char arr[], int x, int y);

int main()
{
    int len;
    char string_number[MAX_LEN];

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

    int w = 1256;
    len = itoa(string_number, MAX_LEN, w);
    reverse(string_number, 0, len-1);
    printf("%d == %s\n", w, string_number);

    int x = 41236124;
    len = itoa(string_number, MAX_LEN, x);
    reverse(string_number, 0, len-1);
    printf("%d == %s\n", x, string_number);

    int y = -41236124;
    len = itoa(string_number, MAX_LEN, y);
    printf("%d == %s\n", y, string_number);

    int z = 0;
    len = itoa(string_number, MAX_LEN, z);
    reverse(string_number, 0, len-1);
    printf("%d == %s\n", z, string_number);

    int q = 1;
    len = itoa(string_number, MAX_LEN, q);
    reverse(string_number, 0, len-1);
    printf("%d == %s\n", q, string_number);

    return 0;
}

int itoa(char arr[], int len, int val)
{
    int res;
    bool negative = false;

    // Handle negative case
    if (val < 0)
    {
        val *= -1;
        negative = true;
    }

    // Begin recursive conversion
    res = convert(arr, len, val, 1, 0);

    if ((res == -1) || (res == len+1)) // Is this correct?
    {
        printf("Error: Insufficient space for conversion; quitting...\n");
        return -1;
    }

    // Add negative if necessary, then reverse
    if (negative){
        arr[res++] = '-';
    }
    arr[res] = '\0';
    reverse(arr, 0, res - 1);

    return 0;
}

int convert(char arr[], int len, int val, int place, int index)
{
    /*
    General idea for computing each place of the string;
    assume we're itoa-ing 1256:

    printf("%d\n", (1256 % 10) / 1);            // prints 6
    printf("%d\n", (1256 % 100) / 10);          // prints 5
    printf("%d\n", (1256 % 1000) / 100);        // prints 2
    printf("%d\n", (1256 % 10000) / 1000);      // prints 1
    printf("%d\n", (1256 % 100000) / 10000);    // prints 0

    This algorithm requires special handling for 0, as shown below.
    */
    int new_val;

    if (index >= len)
    {
        // Buffer overrun
        return -1;
    }

    // Explicitly handle zero
    if (val == 0)
    {
        arr[0] = '0';
        return index+1;
    }

    new_val = (val % (10 * place)) / place;
    if (new_val == 0)
    {
        // computation is finished
        return index;
    }
    else
    {
        arr[index] = (char)(new_val + '0');
        return convert(arr, len, val, place * 10, index + 1);
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
