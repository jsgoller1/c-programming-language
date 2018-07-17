#include <stdio.h>

#include "common.h"

/*
In a two's complement number representation, our version of itoa()
does not handle the largest negative number, that is, the value of n equal
to -(2^wordsize-1). Explain why not. Modify it to print that value correctly,
regardless of the machine on which it runs.

In a two's compliment system, the -(2^wordsize-1) value presents a unique
edge case, as this value this number multiplied by -1 is itself. For 32bit
wordsize, 0x80000000 is the largest and "first" negative number (if we start
at zero and add 1 iteratively until we hit the first negative number). In
itoa(), our do-while loop runs while the parameter n > 0; however passing in
-2147483648 is represented as 0x80000000, which is our edge case. So our
strategy to ensure we never execute our do-while loop on a negative number
fails. Other negative numbers don't have this issue - multiplying them
by -1 produces a positive value.

*/

static void itoa(int n, char s[]) {
  int i, is_negative;
  unsigned val;
  i = 0;

  // If the value is negative, multiply by
  // -1 and store the result as an unsigned int.
  is_negative = (n < 0);
  is_negative ? (val = (unsigned)(n * -1)) : (val = (unsigned)n);

  do {
    s[i++] = val % 10 + '0';
  } while ((val /= 10) > 0);
  if (is_negative) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s, i);
}

int main() {
  char numstring0[MAXLEN];
  int num0 = 0;  // 0
  itoa(num0, numstring0);
  printf("%d == %s\n", num0, numstring0);

  char numstring1[MAXLEN];
  int num1 = 0x7FFFFFFF;  // 2147483647
  itoa(num1, numstring1);
  printf("%d == %s\n", num1, numstring1);

  char numstring2[MAXLEN];
  int num2 = (int)0x80000000;  // -2147483648
  itoa(num2, numstring2);
  printf("%d == %s\n", num2, numstring2);

  char numstring3[MAXLEN];
  int num3 = (int)0xFFFFFFFF;  // -1
  itoa(num3, numstring3);
  printf("%d == %s\n", num3, numstring3);

  return 0;
}
