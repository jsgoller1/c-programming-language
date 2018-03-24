#include "5.2-getint.h"
#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

static int buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;

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

  // Determine sign and skip sign char
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
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

int getch() {
  int gotten;
  gotten = (bufp > 0) ? buf[--bufp] : getchar();
  // printf("Got this: %c == %d\n", gotten, gotten);
  return gotten;
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

int main() {
  int result;
  printf("Enter a number representable as an int: ");
  getint(&result);
  printf("You entered: %d\n", result);
  return 0;
}
