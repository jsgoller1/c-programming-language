#include <stdio.h>

#define def_x int
#define z_string "int z0 is not a variable; this is a string"

typedef td_y in;

int foobar(float float_a, float floatb) { printf("%f\n", a + b); }

int main() {
  int a1;
  int b1;
  int c1, a2;
  int b2 = 0;
  int c2 = 0;
  int a3 = 0, b3 = 0, c3 = 0;
  char a4[] = "int z1 is not a variable";
  printf("Nor is int z2");

  // prints garbage as multiple vars aren't initialized
  printf("%d\n", a1 + a2 + a3 + b1 + b2 + b3 + c1 + c2 + c3);
  return 0;
}
