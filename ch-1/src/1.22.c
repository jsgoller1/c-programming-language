#include "1.22.h"
#include <stdio.h>
#include "common.h"

/*
 * Ex 1.22: Write a program to "fold" long input lines into two or more shorter
 * lines after the last non-blank character that occurs before the n-th column
 * of input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 * ----
 * I'm assuming this question is asking me to replicate the $fold program.
 */

#ifdef DEBUG
#define FOLD_COLUMN 5
#endif

int main() {
#ifdef DEBUG
  char line[MAXLINE];
  int len;
  printf("Begin entering text.\n");
  while ((len = mygetline(line, MAXLINE))) {
    fold(line, MAXLINE, FOLD_COLUMN);
  }
#else
  printf("1.22: No unit tests.\n");
#endif
  return 0;
}

void fold(const char* const line, const int len, const int column) {
  if (column == 0) {
    printf("Error - cannot fold to 0th column.\n");
    return;
  }
  for (int i = 0; i < len && line[i] != '\0'; i++) {
    if (i > 0 && !(i % column)) {
      printf("\n%c", line[i]);
    } else {
      printf("%c", line[i]);
    }
  }
  printf("\n");
}
