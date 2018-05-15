#include <stdio.h>
#include "common.h"

#ifndef DEBUG
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/*
 * Ex 1.17: Write a program to print all input lines that are longer than 80
 * characters.
 */

static int longer_than_80() {
  int len;             // current line length
  char line[MAXLINE];  // current input line

  while ((len = mygetline(line, MAXLINE)) > 0)
    if (len > 80) {
      printf("%d: %s", len - 1, line);
    }
  return 0;
}

int main() {
#ifdef DEBUG
  longer_than_80();
#else
  printf("1.17: No unit tests.\n");
#endif
}
