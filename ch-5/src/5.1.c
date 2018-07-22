#include <ctype.h>
#include <stdio.h>

// Ex 5.1: As written, getint treats a + or - not followed by a digit as a valid
// representation of zero. Fix it to push such a character back on the input.

// getint: get the next inter from input into *pn
static int getint(int* const pn) {
  int c, sign;

  while (isspace(c = getchar())) {
    // no op; skip whitespace
  }

  // If the first char after whitespace isn't a number,
  // we aren't reading a number.
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetc(c, stdin);
    fprintf(stderr, "getint() | error: got invalid char %c in input\n", c);
    return -1;
  }

  // Determine sign and skip sign char
  sign = (c == '-') ? -1 : 1;

  // catch case for "-" being the only input
  if (c == '-') {
    c = getchar();
    if (c == '\n' || c == EOF) {
      fprintf(stderr, "getint() | error: got only '-'\n");
      ungetc('-', stdin);
      return -1;
    }
  }

  // Get each number, keeping a running product
  for (*pn = 0; isdigit(c); c = getchar()) {
    *pn = 10 * *pn + (c - '0');
  }

  *pn *= sign;

  if (c != EOF && c != '\n') {
    ungetc(c, stdin);
    fprintf(stderr, "getint() | error: got invalid char %d in post-input\n", c);
    return -1;
  }

  return 0;
}

int main() {
  int result = 0;
  if ((result = getint(&result)) == -1) {
    fprintf(stderr, "%c was pushed back to stdin.\n", getchar());
    return 0;
  }
  printf("%d\n", result);
  return 0;
}
