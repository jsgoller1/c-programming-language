#include "2.8.h"
#include <stdio.h>

#pragma clang diagnostic ignored "-Wgnu-binary-literal"

/*
Ex 2.8: Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions.
 */

int main() {
  // 0b11010100 = 0xD4
  printf("%x\n", rightrot(0b10100110, 3));

  // 0b00000111 = 0x7
  printf("%x\n", rightrot(0b00111000, 3));

  // 0x00, no effect.
  printf("%x\n", rightrot(0, 3));

  // 0xFF, no effect
  printf("%x\n", rightrot(0b11111111, 3));

  // 0xEFDEADBE
  printf("%x\n", rightrot((unsigned)0xDEADBEEF, 8));

  // 0xEFDEADBE
  printf("%x\n", rightrot((unsigned)0xDEADBEEF, 40));

  return 0;
}

// rightrot(): rotate x to the right n places, with wrapping.
// rightrot() has to use unsigned ints so that C does not
// try to preserve the sign bit if we shift a number with it set.
unsigned int rightrot(unsigned int x, int n) {
  // Rotating 33 places is the same as rotating 1 for a 32bit word.
  if (n >= 32) {
    n = n % 32;
  }

  // capture n lowest bits
  unsigned lowest_mask = (unsigned)~(~0 << n);
  unsigned int lowest = x & lowest_mask;

  // shift x by n to the right
  x = x >> n;

  // take n lowest bits and make them n highest bits
  unsigned int highest = lowest << (32 - n);

  // combine
  return highest | x;
}
