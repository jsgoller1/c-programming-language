#include <stdio.h>

// Ex 1.8: Write a program to count blanks, tabs, and newlines.

static int count_empties() {
  int c, spaces, tabs, newlines;
  spaces = tabs = newlines = 0;

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

int main() { return count_empties(); }
