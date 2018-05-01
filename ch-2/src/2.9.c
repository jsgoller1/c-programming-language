#include "2.9.h"
#include <stdio.h>

/*
Ex 2.9: In a two's complement number system, x &= (x-1) deletes the
rightmost 1-bit in x. Explain why. Use this observation to write a faster
version of bitcount.
*/

int main() {
  /*
  For any number x,
     x = 0b...1
   x-1 = 0b...0
   or vice versa; there's no
   number where its previous value
   and itself share the rightmost bit.
  */

  printf("%d\n", bitcount(0xF013));  // runs in 7 steps instead of 16.
  return 0;
}

int bitcount(unsigned x) {
  int b = 0;

  while (x != 0) {
    /*
    On every iteration, the value x and x-1
    differ in the 0th bit (starting at the right).
    Using x &= x-1, we can "decrement", and capture all
    bits in b steps, where b is equal to the number of bits.
    This is better than the original bitcount() because
    it ran in n time for n-bit strings every time.
    I had to look at the answer manual to figure
    this one out. ;)
    */
    x &= x - 1;
    b++;
  }
  return b;
}
