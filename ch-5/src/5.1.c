#include <ctype.h>
#include <stdio.h>

#include "5.1.h"

// getint: get the next inter from input into *pn
int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch())) {
    // no op; skip whitespace
  }

  // If the first char after whitespace isn't a number,
  // we aren't reading a number.
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
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
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }

  *pn *= sign;

  if (c != EOF) {
    ungetch(c);
  }

  return c;
}

int main() {
  int result = 0;
  printf("Enter a number representable as an int: ");
  getint(&result);
  printf("You entered: %d\n", result);
  return 0;
}
