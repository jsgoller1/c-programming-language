#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j); // technically declared inside qsort in book
void print_arr(int arr[], int left, int right);

int main()
{
    int i;
    int len = 11;
    int arr[] = {2, 6, 3, 8, 1, 5, 9, 4, 7, 10, 0};
    qsort(arr, 0, len-1);
    print_arr(arr, 0, 10);
    printf ("\n");
    return 0;
}

// qsort: sort v[left]...v[right] into increasing order
void qsort(int v[], int left, int right)
{
    int i, last;

    print_arr(v, left, right);
    if (left >= right) // do nothing if array contains fewer than two elements
    {
        return;
    }
    swap(v, left, (left+right)/2); // move partition elem to v[0]
    last = left;
    for (i=left+1; i <= right; i++)
    {
        if (v[i] < v[left])
        {
            swap(v, ++last, i);     
        }
    }
    swap(v, left, last);    // restore partition elem
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

// swap: interchange v[i] and v[j]
void swap(int v[], int i, int j)
{
    int temp;

    printf("swapping %d (v[%d]) and %d (v[%d])\n", v[i], i, v[j], j);
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void print_arr(int arr[], int left, int right)
{
    int i;
    for (i = left; i <= right; i++)
    {
        printf("%d ", arr[i]);
    } 
    printf ("\n");
}