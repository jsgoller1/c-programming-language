#include "2.7.h"
#include <stdbool.h>
#include <stdio.h>
#include "common.h"

/*
Write a function setbits(x,p,n) that inverts the n bits starting at p. Assuming
p = 1 and n = 3

       3 2 p
x = 0b 1 0 1 0
becomes
x = 0b 0 1 0 0
---
Bit flipping can be done via xor - set the bits to flip and leave the other
ones unset:
0 1 0 1 src
1 1 1 1 mask
1 0 1 0 (flipped)

0 1 0 1 src
0 0 0 0 mask
0 1 0 1 (presered)

The solution to this problem is:
1) Create bitmask with bits-to-be-flipped set and others not.
2) xor with x.
*/

int main() {
  printf("0x%x\n", invert(0xff, 0, 4));
  printf("0x%x\n", invert(0xff, 5, 4));
  printf("0x%x\n", invert(0xff, 3, 4));

  return 0;
}

int invert(const int x, const int position, const int count) {
  int mask = 0;
  create_mask(count, position, &mask, false);
  return (x ^ mask);
}
