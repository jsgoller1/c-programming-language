#include <stdio.h>

#ifndef VERBOSE_TEST
#pragma clang diagnostic ignored "-Wunused-function"
#endif

// Ex 1.12: Write a program that prints every word of input on its own line

int print_every_word() {
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

int main() {
#ifdef DEBUG
  print_every_word()();
#else
  printf("1.12: No unit tests.\n");
#endif
}
