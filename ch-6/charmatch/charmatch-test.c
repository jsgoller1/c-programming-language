#include <stdio.h>

#define def_x int
#define z_string "int z0 is not a variable; this is a string"

// int z1; is not a variable, this is a CPP comment

/* int z2; is not a variable, this is a C comment */

typedef td_y int;

int foobar(float float_a, float float_b) { printf("%f\n", a + b); }

int main() {
  int alpha1;
  int beta1;
  int gamma1, alpha12;
  int beta2 = 0;
  int gamma2 = 0;
  int alpha3 = 0, beta3 = 0, gamma3 = 0;
  char alpha4[] = "int z3 is not a variable";
  printf("int z4 is not a variable");
  td_y a5;

  // prints garbage as multiple vars aren't initialized
  printf("%d\n", alpha1 + alpha2 + alpha3 + beta1 + beta2 + beta3 + gamma1 +
                     gamma2 + gamma3);
  return 0;
}
