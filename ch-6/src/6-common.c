#include <stdio.h>

// Ch 4 functions
#include "common.h"

#define BUFSIZE 100

static char buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;

char getch() {
  char gotten;
  gotten = (bufp > 0) ? buf[--bufp] : (char)getchar();
  return gotten;
}

void ungetch(char c) {
  if (bufp >= BUFSIZE) {
  } else {
    buf[bufp++] = c;
  }
}
