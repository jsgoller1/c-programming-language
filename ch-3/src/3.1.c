#include <stdio.h>

#include "3.1.h"

/*
Ex 3.1:  Our binary search makes two tests inside the loop, when one
would suffice (at the price of more tests outside). Write a version with only
one test inside the loop and measure the difference in run-time.
*/

int main() {
  int ints[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
  test(32, ints, 14);
  test(512, ints, 14);
  test(2555, ints, 14);

  return 0;
}

int binsearch(const int x, const int* const v, const int n) {
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

// This is not asypmtotically faster than the other bin search;
// it still takes log(n) steps instead of 3*log(n) steps for an
// array of n integers - both are O(log(n));
int newbinsearch(const int x, const int* const v, const int n) {
  int high, low, mid = 0;

  low = 0;
  high = n - 1;
  while (low <= high && x != v[mid]) {
    mid = (low + high) / 2;
    (x < v[mid]) ? (high = mid - 1) : (low = mid + 1);
  }
  if (x == v[mid]) {
    return mid;
  }
  return -1;  // no match
}

void test(const int val, const int* const v, const int n) {
  printf("binsearch: %d at %d\n", val, binsearch(val, v, n));
  printf("newbinsearch: %d at %d\n", val, newbinsearch(val, v, n));
}
