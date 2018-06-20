#include <stdio.h>

/*
 * 7.2: Write a program that will print arbitrary input in a sensible way. As a
 * minimum, it should print non-graphic characters in octal or hexadecimal
 * according to local custom, and break long text lines.
 * ---
 * Given that this is in a section about format strings, I _think_ they're
 * trying to get at an answer using format strings, but the "sensible" thing
 * to me here is to just pipe to stdout, break up long lines, and convert
 * illegal characters to a legal character signaling the char isn't printable.
 *
 * Not entirely sure what "according to local custom" should mean, but we can
 * filter characters outside of the accepted range.
 */

static int validate_character(const int c) {
  // ignore characters not in the ASCII range
  if (c < 32 || 126 < c) {
    return '\0';
  } else {
    return c;
  }
}

int main() {
  int i = 1;
  int c = 0;
  while ((c = getchar()) != EOF) {
    putchar(validate_character(c));
    if (i % 80 == 0) {
      putchar('\n');
    }
    i++;
  }
  return 0;
}
