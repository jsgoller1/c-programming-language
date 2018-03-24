#include <stdio.h>
#define MAX_LEN 1000

/*
Write the function itob(n,s,b) that converts the integer n
into a base b character representation in the string s. In particular,
itob(n,s, 16) formats n as a hexadecimal integer in s.

For the purposes of this, I am only implementing base 0 through base 36 to avoid
having to pick characters to represent 36+.
*/

void itob(int n, char s[], int b);
void reverse(char s[], int len);

int main() {
  // 1010
  char numstring[MAX_LEN];
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

void itob(int n, char s[], int b) {
  int i, is_negative, remainder;
  unsigned val;
  i = 0;

  // Ignore unsuported inputs
  if ((b < 2) || (b > 36)) {
    printf("Bases 0, 1, and 36+ not supported.\n");
    return;
  }

  // Fix 0x80000000 issue; if the value is negative, multiply by
  // -1 and store the result as an unsigned int.
  is_negative = (n < 0);
  is_negative ? (val = n * -1) : (val = n);

  do {
    remainder = (val % b);
    if (remainder >= 10) {
      // If we go above base 10, start using
      // A through Z; offset is different, and
      // we need to start from 0 (subtract 10).
      (s[i] = ('A' + remainder - 10));
    } else {
      // same logic as itoa()
      (s[i] = '0' + remainder);
    }
    i++;
  } while ((val /= b) > 0);

  if (is_negative) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s, i);
}

void reverse(char s[], int len) {
  int i;
  char temp;
  for (i = 0; i < len / 2; i++) {
    temp = s[len - i - 1];
    s[len - i - 1] = s[i];
    s[i] = temp;
  }
}
