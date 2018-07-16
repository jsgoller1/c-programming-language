#include <stdio.h>

#ifndef DEBUG
#pragma clang diagnostic ignored "-Wunused-function"
#endif

// Ex 1.12: Write a program that prints every word of input on its own line

static int print_every_word() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      putchar('\n');
    else {
      putchar(c);
    }
  }
  putchar('\n');
  return 0;
}

int main() { return print_every_word(); }
