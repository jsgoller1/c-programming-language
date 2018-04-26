#include <stdio.h>

// Ex 1.12: Write a program that prints every word of input on its own line

int main() {
  int c;

  printf("Begin typing, terminate via ctrl-D on an empty line.\n");
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      putchar('\n');
    else {
      putchar(c);
    }
  }
  return 0;
}
