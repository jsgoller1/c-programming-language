#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ... , 300 */

float fahr_to_cels(float fahr);
float cels_to_fahr(float cels);

float fahr_to_cels(float fahr) { return 5.0 / 9.0 * (fahr - 32.0); }

float cels_to_fahr(float cels) { return 32.0 + (cels * (9.0 / 5.0)); }

int main() {
  printf("%f\n", fahr_to_cels(212.0));
  printf("%f\n", fahr_to_cels(32.0));
  printf("%f\n", cels_to_fahr(100.0));
  printf("%f\n", cels_to_fahr(0));
  return 0;
}