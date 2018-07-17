#include <stdio.h>

#include "common.h"

/*
Write the function itob(n,s,b) that converts the integer n
into a base b character representation in the string s. In particular,
itob(n,s, 16) formats n as a hexadecimal integer in s.

For the purposes of this, I am only implementing base 0 through base 36 to avoid
having to pick characters to represent 36+.
*/

static void itob(const int n, unsigned char* const s, const unsigned b) {
  int i;
  unsigned val, remainder;
  i = 0;

  // Ignore unsuported inputs
  if ((b < 2) || (b > 36)) {
    printf("Bases 0, 1, and 36+ not supported.\n");
    return;
  }

  // Fix 0x80000000 issue; if the value is negative, multiply by
  // -1 and store the result as an unsigned int.
  (n < 0) ? (val = (unsigned)(n * -1)) : (val = (unsigned)(n));

  do {
    remainder = (unsigned)(val % b);
    if (remainder >= 10) {
      // If we go above base 10, start using
      // A through Z; offset is different, and
      // we need to start from 0 (subtract 10).
      s[i] = (unsigned char)('A' + remainder - 10);
    } else {
      // same logic as itoa()
      s[i] = (unsigned char)('0' + remainder);
    }
    i++;
  } while ((val /= b) > 0);

  if (n < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse((char*)s, i);
}

int main() {
  // 1010
  unsigned char numstring[MAXLEN];
  int num = 10;
  itob(num, numstring, 2);
  printf("%d base 10 == %s base %d\n", num, numstring, 2);

  // Z
  num = 35;
  itob(num, numstring, 36);
  printf("%d base 10 == %s base %d\n", num, numstring, 36);

  // Quits with error, should print "35 base 10 == Z base 1"
  // since values are unchanged from previous iteration
  num = 35;
  itob(num, numstring, 1);
  printf("%d base 10 == %s base %d\n", num, numstring, 1);

  // 0
  num = 0;
  itob(num, numstring, 10);
  printf("%d base 10 == %s base %d\n", num, numstring, 10);

  return 0;
}
