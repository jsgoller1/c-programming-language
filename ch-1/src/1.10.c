#include <stdio.h>

#ifndef DEBUG
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/*
 * Ex 1.10: Write a program to copy its input to its output, replacing each tab
 * by \t, each backspace by \b, and each backslash by \\. This makes tabs and
 * backspaces visible in an unambiguous way.
 *
 * Note: \b doesn't work on my system, as backspacing just deletes characters up
 * to an empty string, so I'll escape space characters instead.
 */

static int replace_with_escape() {
  int c;

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\\':
        printf("\\\\");
        break;
      case '\t':
        printf("\\t");
        break;
      case ' ':
        printf("\\w");
        break;
      default:
        putchar(c);
        break;
    }
  }
  putchar('\n');
  return 0;
}

int main() { return replace_with_escape(); }
