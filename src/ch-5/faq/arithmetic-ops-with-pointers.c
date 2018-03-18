#include <stdio.h>

int main() {
  /*
  K&R say (p. 102, 2nd ed):
  "...pointers may be compared under certain circumstances. If p and q point to
  members of the same array, then relations like ==, 1=, <, >=, etc., work
  properly. For example, p < q is true if p points to an earlier member of the
  array than q does. Any pointer can be meaningfully compared for equality or
  inequality with zero. But the behavior is undefined for arithmetic or
  comparisons with pointers that do not point to members of the same array."

  Let's confirm that!
  */

  int array1[3] = {0, 1, 2};
  int array2[3] = {5, 6, 7};

  int *ip1, *ip2;

  // < is legal because the array is a contiguous block of bytes
  ip1 = &array1[0];
  ip2 = &array1[1];
  printf("ip1, ip2: %p, %p\n", (void *)ip1, (void *)ip2);
  printf("*ip1, *ip2: %d, %d\n", *ip1, *ip2);
  printf("ip1 < ip2: %d\n", ip1 < ip2);

  // < is undefined; we don't know where each thing is on the stack, and as
  // such, we can't assume that array1 is above or below array2 address-wise.
  ip2 = &array2[1];
  printf("ip1, ip2: %p, %p\n", (void *)ip1, (void *)ip2);
  printf("*ip1, *ip2: %d, %d\n", *ip1, *ip2);
  printf("ip1 < ip2: %d\n", ip1 < ip2);

  return 0;
}
