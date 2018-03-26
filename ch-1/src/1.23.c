#include <stdio.h>

// Write a program to remove all comments from a C program. Run this program on
// its source!

/* ALWAYS USE CURLY BRACES, YOU IDIOT */

int main() {
  int in_single_comment, in_multi_comment; /* this gets removed */
  in_single_comment = in_multi_comment = 0;
  int c, temp, not_used;

  while ((c = getchar()) != EOF) {
    /*
    Check if we're in a single-line comment. There's two edge cases here:
    1 - legitimate divison operator, which should be printed.
    2 - backslashes inside of comments, which should not be.
    */
    if ((c == '/') && (!in_single_comment && !in_multi_comment)) {
      temp = c;
      if ((c = getchar()) == '/') {
        in_single_comment = 1;
      } else if (c == '*') {
        in_multi_comment = 1;
      } else {
        putchar(temp);
      }
    }

    // Correctly exit single-line comments.
    if (in_single_comment) {
      if (c == '\n') {
        in_single_comment = 0;
      }
    }

    // Correctly exit multi-line comments by detecting
    // termination sequence and not printing it.
    if ((c == '*') && in_multi_comment) {
      if ((c = getchar()) == '/') {
        in_multi_comment = 0;
        c = getchar();
      }
    }

    if (!in_single_comment && !in_multi_comment) {
      putchar(c);
    }

    // This doesn't get used, but it should be present
    // when you run this program against its source.
    not_used = 2 / 4;
  }
  return 0;
}