#include <stdio.h>
#include <stdlib.h>

// K&R exercises 5.8 and 5.9 discuss arrays of arrays, and arrays of pointers,
// and the differences between each. Let's explore that some here.

int main() {
  // daytab is an array of pointers to arrays of chars; these could now
  // be of different lengths as opposed to a "true" array of arrays
  char *daytab[3];

  // If we use an array of pointers, each thing pointed-to has to be initialized
  // on its own
  char non_leap_arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char leap_arr[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // Major advantage: arrays of pointers don't have to point to things of the
  // same length!
  char wtf_leap_arr[] = {0, 127, 127, 127};

  daytab[0] = non_leap_arr;
  daytab[1] = leap_arr;
  daytab[2] = wtf_leap_arr;

  printf("daytab: %p\n", (void *)daytab);
  printf("daytab[0]: %p\n", (void *)daytab[0]);
  printf("non_leap_arr: %p\n", (void *)non_leap_arr);
  printf("non_leap_arr[1]: %d\n", non_leap_arr[1]);
  printf("&non_leap_arr[1]: %p\n", (void *)&non_leap_arr[1]);
  printf("non_leap_arr[2]: %d\n", non_leap_arr[2]);
  printf("&non_leap_arr[2]: %p\n\n", (void *)&non_leap_arr[2]);
}
