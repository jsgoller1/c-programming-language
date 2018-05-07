#include <stdio.h>

#ifndef VERBOSE_TEST
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/*
 * Ex 1.5: Modify the temperature conversion program to print the table in
 * reverse order, that is, from 300 degrees to O.
 */

static int reverse_table() {
  int fahr;

  printf("F\tC\n");
  printf("-------------\n");
  for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  return 0;
}

int main() {
#ifdef VERBOSE_TEST
  reverse_table();
#else
  printf("1.5: No unit tests.\n");
#endif
}
