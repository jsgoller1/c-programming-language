#include <stdio.h>

/*
Write a function setbits(x,p,n,y) that returns x with the n
bits that begin at position p set to the rightmost n bits of y, leaving the
other bits unchanged. That is:

Assuming p = 5 and n =3

               p 2 3
x = 0b 1 1 0 0 1 1 0 0 1 1
y = 0b 0 1 0 1 0 1 0 1 0 1

So set those bits to the same in y,
               | | |
x = 0b 1 1 0 0 0 1 0 0 1 1
y = 0b 0 1 0 1 0 1 0 1 0 1
               | | |
*/

unsigned setbits(int x, int y, int position, int count);

int main() {
  // 0b10100110 = 0xA6
  printf("%x\n", setbits(0b10101010, 0b00110100, 3, 2));
  // 0b10101010 = 0xAA (unchanged)
  printf("%x\n", setbits(0b10101010, 0b00111000, 3, 2));
  // 0x01
  printf("%x\n", setbits(0, 0b000001, 3, 4));
  // 0x00
  printf("%x\n", setbits(1, 0b000000, 3, 4));
  return 0;
}

unsigned setbits(int x, int y, int position, int count) {
  if (count == 0) {
    return x;
  }
  // for the comment example, assume:
  // x = 0b00101010
  // y = 0b00110100
  // position = 3
  // count = 2
  int mask, trim_mask, y_bits, new_x;
  mask = trim_mask = 0;

  // Generate correct bitmask; start by creating a mask that
  // gets all bits to the right - we create a mask of all bits
  // set, then shift to the (zero-indexed) position and flip again.
  // Suppose position = 3; then we would generate 0b1...1111,
  // shift to 0b1...0000, then flip to 0b0...1111 = 0xf
  mask = ~(~mask << position + 1);

  // Now, if position >= count, we have to trim the mask; getting
  // all 4+ bits to the right of the 3rd bit is 0b0...1111, but
  // all 2 bits to the right of the 3rd bit is 0b0...1100.
  // So create a new string, flip it to 1s, and shift.
  if (!(position < count)) {
    trim_mask = ~(~trim_mask << (position - count + 1));
  }

  // Now, for the example of position = 3, count = 2, we have
  //      mask = 0b0...1111 = 0xf
  // trim_mask = 0b0...0011 = 0x3
  // If we XOR the two, we'll get the mask we actually want,
  //             0b0...1100 = 0xc
  mask = mask ^ trim_mask;

  // Get required bits from y; to do this, we can just
  // AND with y. y = 0b110100, so with the mask
  // from before, we'd have:
  //               ||
  //   mask: 0b00001100
  //      y: 0b00110100
  //               ||
  // y_bits: 0b00000100 = 0x4
  y_bits = mask & y;

  // Finally, set them in x. We have:
  //   mask: 0b00001100
  // y_bits: 0b00000100
  //      x: 0b10101010
  //  new_x: 0b00000000
  // So to set our new x, we want the
  // current bits of x, except the y-bits
  // set correctly. So zero those bits in new_x,
  new_x = x & (~mask);
  //     x: 0b10101010
  // ~mask: 0b11110011
  // new_x: 0b10100010
  // Now OR with y_bits to set them:
  //  new_x: 0b10100010
  // y_bits: 0b00000100
  new_x = new_x | y_bits;

  return new_x;
}