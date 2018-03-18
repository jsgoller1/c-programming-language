#include "5-common.h"
#include <stdio.h>

#define BUFSIZE 100

static int buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;

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
