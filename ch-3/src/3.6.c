#include <stdio.h>

#include "common.h"

#define MAX_LEN 1000

/*
Write a version of itoa that accepts three arguments instead of
two. The third argument is a minimum field width; the converted number must
be padded with blanks on the left if necessary to make it wide enough.
*/

static void itoa(int n, char s[], int pad) {
  int i = 0;
  unsigned val;

  // If the value is negative, multiply by
  // -1 and store the result as an unsigned int.
  (n < 0) ? (val = (unsigned int)(n * -1)) : (val = (unsigned int)n);

  do {
    s[i++] = val % 10 + '0';
  } while ((val /= 10) > 0);
  if (n < 0) {
    s[i++] = '-';
  }

  // Doesn't execute if we exceed padding
  while (i < pad) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s, i);
}

int main() {
  char numstring[MAX_LEN];
  int num = 0;  // 0
  itoa(num, numstring, 9);
  printf("%s == %d\n", numstring, num);

  num = 10;  // 0
  itoa(num, numstring, 9);
  printf("%s == %d\n", numstring, num);

  num = 1000000;  // 0
  itoa(num, numstring, 9);
  printf("%s == %d\n", numstring, num);

  num = 1000000000;  // 0
  itoa(num, numstring, 9);
  printf("%s == %d\n", numstring, num);

  num = 0x7FFFFFFF;  // 0
  itoa(num, numstring, 9);
  printf("%s == %d\n", numstring, num);

  return 0;
}
