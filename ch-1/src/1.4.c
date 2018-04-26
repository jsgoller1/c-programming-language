#include <stdio.h>

/*
Ex 1.4: Write a program to convert celcius
temps into Fahrenheit. Since C = 5/9 * (F-32),
F = (C * 9/5) + 32
*/

int main() {
  double fahr, celsius, lower, upper, step;

  lower = 0.0;    // lower limit of temperature table
  upper = 300.0;  // upper limit
  step = 20.0;    // size increment

  celsius = lower;
  printf("C\tF\n");
  printf("-------------\n");
  while (celsius <= upper) {
    fahr = (9.0 / 5.0 * celsius) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
