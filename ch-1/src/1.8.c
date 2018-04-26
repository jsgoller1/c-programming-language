#include <stdio.h>

// Ex 1.8: Write a program to count blanks, tabs, and newlines.

int main() {
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
