#include <stdio.h>

/*
Ex 1.9: Write a program to copy its input to its output,
replacing each string of one or more blanks with a single blank.
*/

int main() {
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
