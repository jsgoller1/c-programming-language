#include <stdio.h>

// What happens if you assign to an assignment?

int main() {
  // In C, an assignment operation results in the rvalue.
  int a, b, c, d;
  a = (b = 200);
  d = c = 100;
  printf("%d %d\n", a, b);
  printf("%d %d\n", d, c);
  return 0;
}