#include <stdio.h>
#include <stdlib.h>

// In K&R ex. 5-13, I am not sure how to read insanely long lines from stdin in
// a memory efficient way without storing them in a huge but temporary buffer
// first. I want to see if GNU tail runs into similar issues if I feed it huge
// lines.

// Answer - yes, somehow it manages to handle arbitrarily long lines.

int main() {
  unsigned long long line_len;
  line_len = 0xFFFFFFFF;

  printf("%llu: ", line_len);

  for (unsigned long long i = 0; i < line_len; i++) {
    printf("X");
  }
  printf("\n");

  return 0;
}
