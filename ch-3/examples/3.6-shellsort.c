#include <stdio.h>

void shellsort(int v[], int n);

int main()
{
    int i;
    int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int myints1[10] = {550, 11, 232, 563, 43, 5, 166, 7999, 812, 39};
    shellsort(myints, 10);   
    shellsort(myints1, 10);

    for (i = 0; i < 10; i++)
    {
        printf("%d ", myints[i]);
    }
    printf("\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d ", myints1[i]);
    }
    printf("\n");    
    return 0;
}

void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}