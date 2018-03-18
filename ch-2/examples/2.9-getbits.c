#include <stdio.h>

unsigned bettergetbits(unsigned x, int p, int n);
unsigned getbits(unsigned x, int p, int n);

int main() {
  unsigned x = 0b11001100;
  printf("%x == %x\n", bettergetbits(x, 4, 3), getbits(x, 4, 3));
  return 0;
}

// same as getbits(), but clearer
unsigned bettergetbits(unsigned x, int p, int n) {
  // right shift x by (p+1-n) bits
  // if x is 0b11001100, p is 4, and n is 3,
  // then shift by 4 + 1 - 3 places, or 2 places.
  // x becomes 0b00110011.
  unsigned a = (x >> (p + 1 - n));

  // flip 0 to all 1s, shift it left n spaces, then flip the entire thing
  // for the above, we have 0b0, which is not'd to 0b1...111. Shift left 3,
  // so it becomes 0b1..1000. Then flip again, and we get 0b0...0111.
  unsigned b = ~(~0 << n);

  // bitwise-and then return
  // if we bitwise and 0b0...0111 with 0b00110011,
  // the result is 0b0...011, or 3.
  return a & b;
}

// getbits(): return the decimal value of the n bits to the right of position p
unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}