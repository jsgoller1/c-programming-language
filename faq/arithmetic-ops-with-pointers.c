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

  long array1[5] = {0, 1, 2, 3, 4};
  long array2[3] = {5, 6, 7};

  long *ip1, *ip2;

  // < is legal because the array is a contiguous block of bytes
  ip1 = &array1[0];
  ip2 = &array1[1];
  printf("ip1, ip2: %p, %p\n", (void *)ip1, (void *)ip2);
  printf("*ip1, *ip2: %ld, %ld\n", *ip1, *ip2);
  printf("ip1 < ip2: %d\n", ip1 < ip2);

  // < is undefined; we don't know where each thing is on the stack, and as
  // such, we can't assume that array1 is above or below array2 address-wise.
  ip2 = &array2[1];
  printf("ip1, ip2: %p, %p\n", (void *)ip1, (void *)ip2);
  printf("*ip1, *ip2: %ld, %ld\n", *ip1, *ip2);
  printf("ip1 < ip2: %d\n", ip1 < ip2);

  // if we subtract p1 from p2 below, do we get the number of elements in the
  // array? Yes, make sure to add 1 as the last offset can store a value. This
  // works regardless of types.
  ip1 = &array1[0];
  ip2 = &array1[4];
  printf("ip2 - ip1: %ld\n", ip2 - ip1 + 1);

  /*
  Conclusion: pointer arithmetic is consistent; see K&R p. 103, 2nd ed:
  "The valid pointer operations are assignment of pointers of the same type,
  adding or subtracting a pointer and an integer, subtracting or comparing two
  pointers to members of the same array, and assigning or comparing to zero. All
  other pointer arithmetic is illegal. It is not legal to add two pointers, or
  to multiply or divide or shift or mask them, or to add float or double to
  them, or even, except for void *, to assign a pointer of one type to a pointer
  of another type without a cast."
  */
  return 0;
}
