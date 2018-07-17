#include <stdbool.h>
#include <stdio.h>

#include "2.6.h"
#include "common.h"

/*
Ex 2.6: Write a function setbits(x,p,n,y) that returns x with the n
bits that begin at position p set to the rightmost n bits of y, leaving the
other bits unchanged.
-----
That is, assuming p = 5 and n =3,
n bits of x starting at p:
       | | |
x = 0b 0 0 1 1 0 0 1 1
       7 6 5 4 3 2 1 0

n rightmost bits of y:
                 | | |
y = 0b 0 1 0 1 0 1 0 1
       7 6 5 4 3 2 1 0

So setting the bits of x to the same in y,
       | | |
x = 0b 1 0 1 1 0 0 1 1
y = 0b 0 1 0 1 0 1 0 1
                 | | |

The procedure for doing this is:
1) Capture n rightmost bits in y and shift them to position.
2) Clear n bits starting at p in x.
3) bitwise-or x and y.
*/

int main() {
  int num_tests = 6, passing_tests = 0;
  passing_tests += test(0xff, 0x00, 5, 4, 0x0f);
  passing_tests += test(0xff, 0x0d, 5, 4, 0xdf);
  passing_tests += test(0xff, 0x1d, 0, 4, 0xfd);
  passing_tests += test(0x0, 0xf, 4, 4, 0x78);
  passing_tests += test(0x0, 0xf, 4, 999, -1);
  passing_tests += test(0x0, 0xf, 999, 1, -1);
  if (passing_tests == num_tests) {
    printf("2.6: PASS!\n");
  } else {
    printf("2.6: FAIL - %d tests didn't pass.\n", num_tests - passing_tests);
  }

  return 0;
}

// test(): execute setbits(), test against hypothesis
int test(const int x, const int y, const int position, const int count,
         const int hypothesis) {
  const int z = set_to_rightmost(x, y, position, count);

  if (z == hypothesis) {
    return 1;
  } else {
    return 0;
  }
}

// set_to_rightmost(): set n bits starting at p in x to rightmost bits in y
int set_to_rightmost(int x, const int y, const int position, const int n) {
  int mask = 0;
  if (n > 31 || position > 31) {
    printf("set_to_rightmost(): can't set bits outside of word.\n");
    return -1;
  }

  // 1) capture n rightmost in y, shift them to position
  if (prepare_rightmost(y, position, n, &mask) == -1) {
    return -1;
  }

  // 2) Clear n bits starting at p in x
  clear_bitfield(&x, position, n);

  // 3) bitwise-or x and mask created from rightmost bits in y
  return (x | mask);
}

// prepare_rightmost(): get the rightmost n bits in y,
// and shift them position
int prepare_rightmost(const int y, const int position, const int n,
                      int* const mask) {
  int shiftval;
  if (n > 31 || position > 31) {
    printf("Error: can't set mask larger than wordsize.\n");
    return -1;
  }

  // set all rightmost bits in the bitmask to same as y
  if (create_mask(n, 0, mask, false) == -1) {
    printf("Couldn't create mask.\n");
    return -1;
  }
  *mask &= y;

  // shift to position
  shiftval = (position == 0) ? 0 : position - 1;  // << -x is >> x; avoid this
  *mask = *mask << shiftval;

  return 0;
}
