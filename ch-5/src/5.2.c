#include <ctype.h>
#include <math.h>
#include <stdio.h>

// Ex. 5.2: Write getfloat(), the floating-point analog of getint(). What type
// does getfloat return as its function value?

// getint: get the next inter from input into *pn
static int getdouble(double *const pd) {
  int c, sign;

  while (isspace(c = getchar())) {
    // no op; skip whitespace
  }

  // If the first char after whitespace isn't a number,
  // we aren't reading a number.
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetc(c, stdin);
    return 0;
  }

  // Determine sign and skip sign char; catch case for "-" being the only input
  sign = (c == '-') ? -1 : 1;
  if (c == '-') {
    c = getchar();
    if (c == '\n' || c == EOF) {
      printf("getdouble() | Error: '-' is invalid.\n");
      ungetc('-', stdin);
      return -1;
    }
  }

  // Get each number, keeping a running product
  for (*pd = 0; isdigit(c); c = getchar()) {
    *pd = 10 * *pd + (c - '0');
  }

  // Get fractional part by successively dividing each character
  // past the decimal by the appropriate power of 10 and adding
  // to a running sum;
  if (c == '.') {
    double digit, fractional, divisor;
    double ten_pow = 1;

    c = getchar();
    for (fractional = 0.0; isdigit(c); c = getchar(), ten_pow++) {
      digit = (c - '0');
      divisor = 1 / (pow(10, ten_pow));
      fractional += digit * divisor;
    }
    *pd += fractional;
  }

  *pd *= sign;

  if (c != EOF && c != '\n') {
    ungetc(c, stdin);
    printf("getdouble() | Got invalid character %c in post-input.\n", c);
    return -1;
  }

  return 0;
}

int main() {
  double result = 0.0;
  if (getdouble(&result) == -1) {
    fprintf(stderr, "%c was pushed back to stdin.\n", getchar());
    return 0;
  }
  printf("%f\n", result);
  return 0;
}
