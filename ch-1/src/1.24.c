#include <stdio.h>

/*
Ex 1.24: Write a program to check a C program for rudimentary syntax
errors like unbalanced parentheses, brackets and braces. Don't forget about
quotes, both single and double, escape sequences, and comments. (This
program is hard if you do it in full generality.)
*/

int main() {
  int in_comment = 0, quotes = 0, ticks = 0, paren_l = 0, paren_r = 0,
      curly_l = 0, curly_r = 0, square_l = 0, square_r = 0, comment_braces = 0;
  int c;

  while ((c = getchar()) != EOF) {
    // Check if we're in a comment
    if (comment_braces == 2) {
      in_comment = 1;
    }

    if (c == '\n') {
      comment_braces = in_comment = 0;
    }

    if (!in_comment) {
      switch (c) {
        case '/':
          comment_braces++;
          break;
        case '"':
          quotes++;
          break;
        case '\'':
          ticks++;
          break;
        case '(':
          paren_l++;
          break;
        case ')':
          paren_r++;
          break;
        case '{':
          curly_l++;
          break;
        case '}':
          curly_r++;
          break;
        case '[':
          square_l++;
          break;
        case ']':
          square_r++;
          break;
      }
    }
  }
  printf(
      " quotes: %d\n ticks: %d\n paren_l: %d\n paren_r: %d\n curly_l: %d\n "
      "curly_r: %d\n square_l: %d\n square_r: %d\n",
      quotes, ticks, paren_l, paren_r, curly_l, curly_r, square_l, square_r);
  if ((quotes % 2) != 0) {
    printf("Program has mismatched closing/opening double quotes.\n");
  } else if ((ticks % 2) != 0) {
    printf("Program has mismatched closing/opening single-ticks.\n");
  } else if (paren_l != paren_r) {
    printf("Program has mismatched parens.\n");
  } else if (curly_l != curly_r) {
    printf("Program has mismatched curly braces.\n");
  } else if (square_l != square_r) {
    printf("Program has mismatched square braces.\n");
  } else {
    printf("Program is possibly correct.\n");
  }

  return 0;
}
