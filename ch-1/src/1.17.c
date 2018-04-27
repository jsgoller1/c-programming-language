#include <stdio.h>
#include "common.h"

/*
Ex 1.17: Write a program to print all input lines that are longer than 80
characters.
*/

#define MAXLINE 1000  // maximum input line size

int main() {
  int len;             // current line length
  char line[MAXLINE];  // current input line

  while ((len = mygetline(line, MAXLINE)) > 0)
    if (len > 80) {
      printf("%d: %s", len - 1, line);
    }
  return 0;
}
