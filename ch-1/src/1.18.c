#include <stdio.h>
#include "common.h"

#ifndef DEBUG
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/*
Ex 1.18: Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines.
*/

static int remove_trailing() {
  int len, last;       // current line length, and string index
  char line[MAXLINE];  // current input line

  while ((len = mygetline(line, MAXLINE)) > 0) {
    last = len - 2;  // remove \n\0
    while (((line[last] == ' ') || (line[last] == '\t')) && len >= 0) {
      line[last] = '\n';
      last--;
    }
    line[last + 2] = '\0';  // if no trailing spaces, line[len] is the null
                            // terminator so this is safe

    if (last > 0) {
      printf("%s", line);
    }
  }
  return 0;
}

int main() {
#ifdef DEBUG
  remove_trailing();
#else
  printf("1.18: No unit tests.\n");
#endif
}
