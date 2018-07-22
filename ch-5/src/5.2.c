#include <ctype.h>
#include <math.h>
#include <stdio.h>

#include "5.2.h"
#include "common.h"

// Write getfloat(), the floating-point analog of getint(). What type does
// getfloat return as its function value?

// getint: get the next inter from input into *pn
int getdouble(double *const pd) {
  int c, sign;

  while (isspace(c = getch())) {
    // no op; skip whitespace
  }

  // If the first char after whitespace isn't a number,
  // we aren't reading a number.
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c);
    return 0;
  }

  // Determine sign and skip sign char; catch case for "-" being the only input
  sign = (c == '-') ? -1 : 1;
  if (c == '-') {
    c = getch();
    if (c == '\n') {
      printf("Error: '-' is invalid.\n");
      ungetch('-');
      return -1;
    }
  }

  // Get each number, keeping a running product
  for (*pd = 0; isdigit(c); c = getch()) {
    *pd = 10 * *pd + (c - '0');
  }

  // Get fractional part by successively dividing each character
  // past the decimal by the appropriate power of 10 and adding
  // to a running sum;
  if (c == '.') {
    double digit, fractional, divisor;
    double ten_pow = 1;

    c = getch();
    for (fractional = 0.0; isdigit(c); c = getch(), ten_pow++) {
      digit = (c - '0');
      divisor = 1 / (pow(10, ten_pow));
      fractional += digit * divisor;
    }
    *pd += fractional;
  }

  *pd *= sign;

  if (c != EOF) {
    ungetch(c);
  }

  return c;
}

int main() {
  double result = 0.0;
  getdouble(&result);
  printf("%f\n", result);
  return 0;
}
