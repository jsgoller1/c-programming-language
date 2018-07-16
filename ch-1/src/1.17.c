#include <stdio.h>

#include "common.h"

/*
 * Ex 1.17: Write a program to print all input lines that are longer than 80
 * characters.
 */

static int longer_than_80() {
  int len;            // current line length
  char line[MAXLEN];  // current input line

  while ((len = mygetline(line, MAXLEN)) > 0)
    if (len > 80) {
      printf("%d: %s", len - 1, line);
    }
  return 0;
}

int main() { return longer_than_80(); }
