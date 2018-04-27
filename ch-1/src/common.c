#include "common.h"
#include <stdio.h>

// mygetline(): read a line into line[], return length
// Always returns a null terminated string.
int mygetline(char line[], const int maxline) {
  int c = 0, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = (char)c;
  }
  if (c == '\n') {
    line[i] = (char)c;
    ++i;
  }
  line[i] = '\0';
  return i;
}
