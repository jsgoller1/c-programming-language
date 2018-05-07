#include <stdio.h>

#ifndef VERBOSE_TEST
#pragma clang diagnostic ignored "-Wunused-function"
#endif

// Ex 1.8: Write a program to count blanks, tabs, and newlines.

static int count_empties() {
  int c, spaces, tabs, newlines;
  spaces = tabs = newlines = 0;

  printf("Begin typing, terminate via ctrl-D on an empty line.\n");
  while ((c = getchar()) != EOF) switch (c) {
      case ' ':
        spaces++;
        break;
      case '\t':
        tabs++;
        break;
      case '\n':
        newlines++;
        break;
    }
  printf("spaces: %d\ntabs: %d\nnewlines: %d\n\n", spaces, tabs, newlines);
  return 0;
}

int main() {
#ifdef VERBOSE_TEST
  count_empties();
#else
  printf("1.8: No unit tests.\n");
#endif
}
