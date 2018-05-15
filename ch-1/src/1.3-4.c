#include <stdio.h>

#ifndef DEBUG
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/*
 * Ex 1.3: Modify the temperature conversion program
 * to print a heading above the table.
 * Ex 1.4: Write a program to convert celcius
 * temps into Fahrenheit. Since C = 5/9 * (F-32),
 * F = (C * 9/5) + 32.
 */

#define LOWER 0.0    // lower limit of temperature table
#define UPPER 300.0  // upper limit
#define STEP 20.0    // size increment

static int cels_to_fahr() {
  double fahr, celsius;

  celsius = LOWER;
  printf("C\tF\n");
  printf("-------------\n");
  while (celsius <= UPPER) {
    fahr = (9.0 / 5.0 * celsius) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + STEP;
  }

  return 0;
}

int main() {
#ifdef DEBUG
  cels_to_fahr();
#else
  printf("1.3-4: No unit tests.\n");
#endif
}
