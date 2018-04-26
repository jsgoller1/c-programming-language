#include <stdio.h>

// Ex 1.6: Verify that the expression `getchar() != EOF` is 0 or 1.

int main() {
  int c = getchar();
  if (c == EOF) {  // getchar == EOF is 1 (or possibly some other nonzero value,
                   // but `==` should only evaluate to 0 or 1)
    printf("getchar() returned EOF.\n");
    return 0;
  } else {  // getchar == EOF is 0
    printf("getchar() didn't return EOF.\n");
    return 0;
  }
}
