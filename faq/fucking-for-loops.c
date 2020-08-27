#include <stdio.h>

// How do I avoid off-by-one errors with for-loops?

int main() {
  int i;
  int nums[5] = {0, 1, 2, 3, 4};

  // nums is {0,1,2,3,4}, so the first char is arr[0] and the last one is
  // arr[4], but len(arr) is 5. Generally, your options for going through arrays
  // are:

  // Option 1: start at zero, middle condition is "less than length", increment.
  for (i = 0; i < 5; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  // Option 2: start at zero, middle condition is "less or equal to last index",
  // increment.
  for (i = 0; i <= 4; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  // Option 3: Go in reverse - start at the last element index, middle condition
  // is "greater than or equal to zero", and decrement.
  for (i = 4; i >= 0; i--) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  // Anything else is off-by-one
  // Common mistake #1 - middle condition is "less than or equal to length"
  // for (i = 0; i <= 5; i++)
  for (i = 0; i <= 5; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  // Common mistake #2 - while reverse-iterating, use "greater than zero"
  for (i = 4; i > 0; i--) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}
