#include "2.6.h"
#include <stdio.h>

#pragma clang diagnostic ignored "-Wgnu-binary-literal"

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
  test(0xff, 0x00, 5, 4, 0x0f);
  test(0xff, 0x0d, 5, 4, 0xdf);
  test(0xff, 0x1d, 0, 4, 0xfd);
  test(0x0, 0xf, 4, 4, 0x78);
  test(0x0, 0xf, 4, 999, -1);
  test(0x0, 0xf, 999, 1, -1);

  return 0;
}

// setbits(): set n bits starting at p in x to rightmost bits in y
int setbits(int x, const int y, const int position, const int n) {
  int mask = 0;
  if (n > 31 || position > 31) {
    printf("Error: can't set bits outside of word.\n");
    return -1;
  }

  // 1) capture n rightmost in y, shift them to position
  if (create_rightmost_mask(y, position, n, &mask) == -1) {
    return -1;
  }

  // 2) Clear n bits starting at p in x
  clear_bitfield(&x, position, n);

  // 3) bitwise-or x and mask created from rightmost bits in y
  printf("x: %x\n", x);
  printf("mask: %x\n", mask);
  return (x | mask);
}

// create_rightmost_mask(): get the rightmost n bits in y,
// and shift them position
int create_rightmost_mask(const int y, const int position, const int n,
                          int* const mask) {
  int shiftval;
  if (n > 31 || position > 31) {
    printf("Error: can't set mask larger than wordsize.\n");
    return -1;
  }

  // set all rightmost bits in the bitmask, then
  // bitwise-and the mask with y to set the same as y
  *mask = set_rightmost(n);
  *mask &= y;
  shiftval = (position == 0) ? 0 : position - 1;  // << -x is >> x; avoid this
  *mask = *mask << shiftval;

  return 0;
}

// clear_bitfield(): clears n bits starting at position in x
int clear_bitfield(int* const x, const int position, const int n) {
  int mask, shiftval;

  if (n > 31 || position > 31) {
    printf("Error: can't clear bits outside of word.\n");
    return -1;
  }

  // create mask with n bits starting at p set
  mask = set_rightmost(n);
  shiftval = (position == 0) ? 0 : position - 1;  // << -x is >> x; avoid this
  mask = mask << shiftval;

  // flip the mask
  mask = ~mask;

  // bitwise-and mask with x to clear bits in x
  *x &= mask;
  return 0;
}

// create_rightmost_mask(): returns an int that has the n rightmost bits set.
int set_rightmost(const int n) {
  int i, rightmost_mask;

  if (n > 31) {
    printf("Error: can't set bits outside of word.\n");
    return -1;
  }
  for (i = 0, rightmost_mask = 0; i < n; i++) {
    rightmost_mask = rightmost_mask << 1;
    rightmost_mask++;
  }

  return rightmost_mask;
}

// test(): execute function, test against hypothesis
void test(const int x, const int y, const int position, const int count,
          const int hypothesis) {
  const int z = setbits(x, y, position, count);
  printf("x: 0x%x\n", x);
  printf("y: 0x%x\n", y);
  printf("Set %d bits at %d\n", count, position);
  if (z == hypothesis) {
    printf("PASS: result: 0x%x, expected: 0x%x\n\n", z, hypothesis);
  } else {
    printf("FAIL: result: 0x%x, expected: 0x%x\n\n", z, hypothesis);
  }
}
