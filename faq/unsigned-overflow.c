#include <stdio.h>

/*
 * Appendix A of K&R says:
 * Unsigned integers, declared using the keyword unsigned, obey the laws of
 * arithmetic modulo 2^n where n is the number of bits in the representation,
 * and thus arithmetic on unsigned quantities can never overflow.
 *
 * So what happens if we try to overflow it anyways?
 */

int main() {
  // Prints 4294967294 or 0xfffffffe. Wat?
  unsigned int max = 0xFFFFFFFF;
  printf("%u + %u = %u\n", max, max, max + max);
  printf("%x + %x = %x\n", max, max, max + max);

  // What happens if we do this with long types?
  // We see that the true result is 0x1fffffffe;
  // the lower 32 bits are set, but since the int couldn't
  // hold the 33rd bit, it was chopped off - no overflow occurred.
  unsigned long lmax = 0x00000000FFFFFFFF;
  printf("%lu + %lu = %lu\n", lmax, lmax, lmax + lmax);
  printf("%lx + %lx = %lx\n", lmax, lmax, lmax + lmax);
}
