#include "1.15.h"
#include <stdio.h>
#include "tests.h"

/*
 * Ex 1.15: Rewrite the temperature conversion program of Section 1.2 to use a
 * function for conversion.
 */

static void test_f_to_c(const double f, const double expected,
                        const char* const message) {
  const double actual = fahr_to_cels(f);
#ifdef TEST_MESSAGES
  printf("fahr_to_cels(): %s\n", message);
#endif
#ifdef DEBUG
  printf("Expected: %f\n", expected);
  printf("Actual: %f\n", actual);
#endif
  assert_double_eq(actual, expected, .1);
}

static void test_c_to_f(const double c, const double expected,
                        const char* const message) {
  const double actual = cels_to_fahr(c);
#ifdef TEST_MESSAGES
  printf("cels_to_fahr(): %s\n", message);
#endif
#ifdef DEBUG
  printf("Expected: %f\n", expected);
  printf("Actual: %f\n", actual);
#endif
  assert_double_eq(actual, expected, .1);
}

int main() {
  printf("1.15: Running tests...\n");
  test_f_to_c(212.0, 100.0, "normal input");
  test_f_to_c(0.0, -17.777, "0.0 input");
  test_f_to_c(-10.0, -23.333, "negative input");
  test_c_to_f(100.0, 212.0, "normal input");
  test_c_to_f(0.0, 32.0, "0.0 input");
  test_c_to_f(-17.777, 0.0, "negative input");
  printf("1.15: PASS!\n");

  return 0;
}

// fahr_to_cels() / cels_to_fahr(): convert temperatures from C to F or vice
// versa
double fahr_to_cels(const double fahr) { return 5.0 / 9.0 * (fahr - 32.0); }
double cels_to_fahr(const double cels) { return 32.0 + (cels * (9.0 / 5.0)); }
