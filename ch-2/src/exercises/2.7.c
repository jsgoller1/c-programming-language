#include <stdio.h>

/*
Write a function setbits(x,p,n) that inverts the n bits starting at p:

Assuming p = 5 and n = 3

               p 2 3
x = 0b 1 1 0 0 1 1 0 0 1 1
returns
x = 0b 1 1 0 0 0 0 1 0 1 1
*/

unsigned invert(int x, int position, int count);

int main() {
  // 0b10100110 = 0xA6
  printf("%x\n", invert(0b10101010, 3, 2));
  // 0b00111000 = 0x38
  printf("%x\n", invert(0b00110100, 3, 2));
  // 0x0F
  printf("%x\n", invert(0, 3, 4));
  // 0xF0
  printf("%x\n", invert(0b11111111, 3, 4));
  return 0;
}

unsigned invert(int x, int position, int count) {
  if (count == 0) {
    return x;
  }
  int mask, trim_mask, inversion_bits, new_x;
  mask = trim_mask = 0;

  // Set mask; see exercise 2.6 for explanation
  mask = ~(~mask << position + 1);
  if (!(position < count)) {
    trim_mask = ~(~trim_mask << (position - count + 1));
  }
  mask = mask ^ trim_mask;

  // Get required bits from x, inverted; to do this:
  // inversion_bits = mask AND x
  // inversion_bits = ~inversion_bits
  // inversion_bits = mask & inversion_bits
  //                       ||
  //           mask: 0b00001100
  //              x: 0b10101010
  //                       ||
  // inversion_bits: 0b00001000
  //~inversion_bits: 0b11110111
  //                       ||
  //           mask: 0b00001100
  //                       =
  // inversion_bits: 0b00000100
  inversion_bits = mask & x;
  inversion_bits = ~inversion_bits;
  inversion_bits = mask & inversion_bits;

  // Finally, set them in x. We have:
  //          ~mask: 0b11110011
  // inversion_bits: 0b00000100
  //              x: 0b10101010
  //          new_x: 0b10100110
  // So to set our new x, we want the
  // current bits of x, except the inverted ones
  new_x = (x & (~mask)) | inversion_bits;

  return new_x;
}