#include <stdio.h>

// count lines in input, ver. 1

int main() {
  int c, n1;

  n1 = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n') ++n1;
  printf("%d\n", n1);  // Note that this will count newlines as characters!
  return 0;
}