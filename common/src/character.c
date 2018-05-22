#include <stdio.h>
#include "common.h"

/*
 * --------------------------------------------------------
 *  Character I/O
 * --------------------------------------------------------
 */

#define BUFSIZE 100
static int buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;

// getch(): Read characters from input or the character buffer
int getch() {
  int gotten;
  gotten = (bufp > 0) ? buf[--bufp] : getchar();
  return gotten;
}

// ungetch(): push characters back to the character buffer
void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}
