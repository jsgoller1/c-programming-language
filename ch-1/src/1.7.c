#include <stdio.h>

// Ex 1.7: Write a program to print the value of EOF

int main() {
#ifdef DEBUG
  printf("EOF: %d\n", EOF);
#else
  printf("1.7: No unit tests.\n");
#endif
  return 0;
}
