#include <stdbool.h>
#include <stdio.h>
#include "common.h"

/*
 * --------------------------------------------------------
 *  Bitwise functions
 * --------------------------------------------------------
 */

// create_mask(): creates a bitmask where n bits starting at position
// are set (least significant bit is position 0); if inverted is set,
// the bitwise-not of this mask is created instead.
int create_mask(const int n, const int position, int *const mask,
                const bool inverted) {
  int i, shiftval;

  if (n > 31 || position > 31) {
    printf("Error: can't set bits outside of word.\n");
    return -1;
  }

  // first set n bits
  for (i = 0, *mask = 0; i < n; i++) {
    *mask = *mask << 1;
    (*mask)++;
  }

  // then shift them into position
  shiftval = (position == 0) ? 0 : position - 1;  // << -x is >> x; avoid this
  *mask = *mask << shiftval;

  if (inverted) {
    *mask = ~(*mask);
  }

  return 0;
}

// clear_bitfield(): clears n bits starting at position in x
int clear_bitfield(int *const x, const int position, const int n) {
  int mask = 0;

  if (n > 31 || position > 31) {
    printf("Error: can't clear bits outside of word.\n");
    return -1;
  }

  // create inverted mask with n bits starting at p set
  if (create_mask(n, position, &mask, true) == -1) {
    printf("Error: couldn't create mask.\n");
    return -1;
  }

  // bitwise-and mask with x to clear bits in x
  *x &= mask;
  return 0;
}
