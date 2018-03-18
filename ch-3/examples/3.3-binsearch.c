#include <stdio.h>

int binsearch(int x, int v[], int n);

// binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]

int main() {
  int ints[] = {0, 1, 33, 55, 673, 11102, 55503, 99999};
  printf("%d\n", binsearch(33, ints, 7));
  printf("%d\n", binsearch(673, ints, 7));
  printf("%d\n", binsearch(356, ints, 7));

  return 0;
}

int binsearch(int x, int v[], int n) {
  int high, low, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else  // found match
    {
      return mid;
    }
  }
  return -1;  // no match
}
