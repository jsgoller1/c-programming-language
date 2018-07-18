#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

/*
 * Ex. 4.2: Extend atof to handle scientific notation of the form 123.45e-6
 * where a floating-point number may be followed by e or E and an
 * optionally signed exponent.
 */

// myatof() - convert string s to double
static double myatof(const char* const s) {
  char sn_exp[MAXLEN];
  double val, power;
  int i, j, sign, sn_sign, sn_val;

  for (i = 0; isspace(s[i]); i++) {
  }  // no-op, skip whitespace

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-') {
    i++;
  }

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.') {
    i++;
  }

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  // call atoi() on the remaining values in the string,
  // and combine result to our power converstion depending
  // on its sign.
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    if (s[i] == '-') {
      sn_sign = 1;
      i++;
    } else {
      sn_sign = 0;
    }
    for (j = 0; isdigit(s[i]); i++, j++) {
      sn_exp[j] = s[i];
    }
    sn_exp[j] = '\0';

    sn_val = atoi(sn_exp);

    // Normally for scientific notation, you
    // multiply for positive exponents, but
    // we are dividing in the return statement
    // of atof(), so multiplying power by 10
    // here makes the returned value smaller.
    if (sn_sign) {
      while (sn_val > 0) {
        power *= 10.0;
        sn_val--;
      }
    } else {
      while (sn_val > 0) {
        power /= 10.0;
        sn_val--;
      }
    }
  }

  return sign * (val / power);
}

int main() {
  char line[MAXLEN];

  while (mygetline(line, MAXLEN) > 0) {
    printf("%f\n", myatof(line));
  }

  return 0;
}
