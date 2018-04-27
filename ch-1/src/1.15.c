#include "1.15.h"
#include <stdio.h>

/*
Ex 1.15: Rewrite the temperature conversion program of Section 1.2 to use a
function for conversion.
*/

// fahr_to_cels() / cels_to_fahr(): convert temperatures from C to F or vice
// versa
double fahr_to_cels(const double fahr) { return 5.0 / 9.0 * (fahr - 32.0); }
double cels_to_fahr(const double cels) { return 32.0 + (cels * (9.0 / 5.0)); }

int main() {
  printf("%f\n", fahr_to_cels(212.0));
  printf("%f\n", fahr_to_cels(32.0));
  printf("%f\n", cels_to_fahr(100.0));
  printf("%f\n", cels_to_fahr(0));
  return 0;
}
