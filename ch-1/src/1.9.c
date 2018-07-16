#include <stdio.h>

/*
 * Ex 1.9: Write a program to copy its input to its output,
 * replacing each string of one or more blanks with a single blank.
 */

static int replace_blanks() {
  int c = 0, space = 0;

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
  putchar('\n');
  return 0;
}

int main() { return replace_blanks(); }
