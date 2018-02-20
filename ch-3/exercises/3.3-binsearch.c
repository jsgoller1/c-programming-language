#include <stdio.h>

int binsearch(int x, int v[], int n);
int newbinsearch(int x, int v[], int n);


// Our binary search makes two tests inside the loop, when one
// would suffice (at the price of more tests outside). Write a version with only one
// test inside the loop and measure the difference in run-time.

int main()
{
    int ints[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    printf("%d\n", binsearch(32, ints, 14));
    printf("%d\n", newbinsearch(32, ints, 14));
    printf("%d\n", binsearch(512, ints, 14));
    printf("%d\n", newbinsearch(512, ints, 14));
    printf("%d\n", binsearch(2555, ints, 14));
    printf("%d\n", newbinsearch(2555, ints, 14));

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int high, low, mid;

    low = 0;
    high = n -1;
    while (low <= high)
    {
        mid = (low+high)/2;
        if (x < v[mid])
        {
            high = mid - 1;
        } else if ( x > v[mid]) 
        {
            low = mid + 1;
        } else // found match 
        { 
            return mid;
        }
    }
    return -1; // no match
}

// This is not asypmtotically faster than the other bin search;
// it still takes log(n) steps instead of 3*log(n) steps for an
// array of n integers - both are O(log(n));
int newbinsearch(int x, int v[], int n)
{
    int high, low, mid;

    low = 0;
    high = n -1;
    while (low <= high && v[mid] != x)
    {
        mid = (low+high)/2;
        (x < v[mid]) ? (high = mid - 1) : (low = mid + 1);
    }
    if (x == v[mid])
    {
        return mid;
    }
    return -1; // no match
}