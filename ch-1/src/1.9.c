#include <stdio.h>

#ifndef DEBUG
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/*
 * Ex 1.9: Write a program to copy its input to its output,
 * replacing each string of one or more blanks with a single blank.
 */

static int replace_blanks() {
  int c = 0, space = 0;

  printf("Begin typing, terminate via ctrl-D on an empty line.\n");
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      space = 1;
    } else {
      if (space == 1) {
        putchar(' ');
        space = 0;
      }
      putchar(c);
    }
  }
  return 0;
}

int main() {
#ifdef DEBUG
  replace_blanks();
#else
  printf("1.9: No unit tests.\n");
#endif
}
