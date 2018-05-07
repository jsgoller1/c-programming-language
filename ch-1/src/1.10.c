#include <stdio.h>

#ifndef VERBOSE_TEST
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/*
 * Ex 1.10: Write a program to copy its input to its output, replacing each tab
 * by \t, each backspace by \b, and each backslash by \\. This makes tabs and
 * backspaces visible in an unambiguous way.
 *
 * Note: \b doesn't work on my system, as backspacing just deletes characters up
 * to an empty string, so I'll do this for spaces too.
 */

static int replace_with_escape() {
  int c;

  printf("Begin typing, terminate via ctrl-D on an empty line.\n");
  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\\':
        printf("\\\\");
        break;
      case '\t':
        printf("\\t");
        break;
      case ' ':
        printf(".");
        break;
      default:
        putchar(c);
        break;
    }
  }
  return 0;
}

int main() {
#ifdef DEBUG
  replace_with_escape();
#else
  printf("1.10: No unit tests.\n");
#endif
}
