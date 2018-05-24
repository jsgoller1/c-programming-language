#include "tests.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * --------------------------------------------------------
 *  Tests
 * --------------------------------------------------------
 *
 * This is a simple testing library I wrote around the assert(3) macro; I
 * looked into some other testing libraries like cmocka but most of them were
 * overkill for my needs.
 */

// assert_ints_*(): compare integers
void assert_int_eq(const int actual, const int expected,
                   const char* const func_name, const char* const message) {
#ifdef TEST_MESSAGES
  printf("%s(): %s\n", func_name, message);
#else
  (void)func_name;
  (void)message;
#endif
#ifdef DEBUG
  printf("Expected: %d\n", expected);
  printf("Actual: %d\n\n", actual);
#endif
  assert(actual == expected);
}

void assert_int_neq(const int actual, const int expected,
                    const char* const func_name, const char* const message) {
#ifdef TEST_MESSAGES
  printf("%s(): %s\n", func_name, message);
#else
  (void)func_name;
  (void)message;
#endif
#ifdef DEBUG
  printf("Expected: %d\n", expected);
  printf("Actual: %d\n\n", actual);
#endif
  assert(actual != expected);
}

// assert_double_*(): compare equality of doubles to arbitrary precision
void assert_double_eq(const double actual, const double expected,
                      const double error, const char* const func_name,
                      const char* const message) {
  const double difference = fabs(actual - expected);
#ifdef TEST_MESSAGES
  printf("%s(): %s\n", func_name, message);
#else
  (void)func_name;
  (void)message;
#endif
#ifdef DEBUG
  printf("Expected: %f\n", expected);
  printf("Actual: %f\n", actual);
  printf("Difference: %f/n\n", difference);
#endif
  assert(difference < error);
}
void assert_double_neq(const double actual, const double expected,
                       const double error, const char* const func_name,
                       const char* const message) {
  const double difference = fabs(actual - expected);
#ifdef TEST_MESSAGES
  printf("%s(): %s\n", func_name, message);
#else
  (void)func_name;
  (void)message;
#endif
#ifdef DEBUG
  printf("Expected: %f\n", expected);
  printf("Actual: %f\n", actual);
  printf("Difference: %f/n\n", difference);
#endif
  assert(difference > error);
}

// assert_strings_*(): compare strings via strcmp(); assumes strings are null
// terminated
void assert_string_eq(const char* const actual, const char* const expected,
                      const char* const func_name, const char* const message) {
#ifdef TEST_MESSAGES
  printf("%s(): %s\n", func_name, message);
#else
  (void)func_name;
  (void)message;
#endif
#ifdef DEBUG
  printf("Expected: %s\n", expected);
  printf("Actual: %s\n\n", actual);
#endif
  assert(strcmp(actual, expected) == 0);
}

void assert_string_neq(const char* const actual, const char* const expected,
                       const char* const func_name, const char* const message) {
#ifdef TEST_MESSAGES
  printf("%s(): %s\n", func_name, message);
#else
  (void)func_name;
  (void)message;
#endif
#ifdef DEBUG
  printf("Expected: %s\n", expected);
  printf("Actual: %s\n\n", actual);
#endif
  assert(strcmp(actual, expected) != 0);
}

// assert_<bool>(): assert truthiness / falsity of expression
void assert_true(const bool expr, const char* const func_name,
                 const char* const message) {
#ifdef TEST_MESSAGES
  printf("%s(): %s\n", func_name, message);
#else
  (void)func_name;
  (void)message;
#endif
#ifdef DEBUG
  printf("Expected: %d\n", expr);
  printf("Actual: %d\n\n", 1);
#endif
  assert(expr);
}
void assert_false(const bool expr, const char* const func_name,
                  const char* const message) {
#ifdef TEST_MESSAGES
  printf("%s(): %s\n", func_name, message);
#else
  (void)func_name;
  (void)message;
#endif
#ifdef DEBUG
  printf("Expected: %d\n", expr);
  printf("Actual: %d\n\n", 0);
#endif
  assert(!(expr));
}

/* Broken, don't use.

// assert_mem_*(): Compare regions of memory via memcmp()
void assert_mem_eq(const void* const actual, const void* const expected,
                   const int size, const char* const func_name,
                   const char* const message) {
#ifdef TEST_MESSAGES
  printf("%s(): %s\n", func_name, message);
#else
  (void)func_name;
  (void)message;
#endif
  const int result = memcmp(actual, expected, (unsigned long)size);
#ifdef DEBUG
  printf("Expected: 0\n");
  printf("Actual: %d\n\n", result);
#endif
  assert(result == 0);
}
void assert_mem_neq(const void* const actual, const void* const expected,
                    const int size, const char* const func_name,
                    const char* const message) {
#ifdef TEST_MESSAGES
  printf("%s(): %s\n", func_name, message);
#else
  (void)func_name;
  (void)message;
#endif
  const int result = memcmp(actual, expected, (unsigned long)size);
#ifdef DEBUG
  printf("Expected: nonzero\n");
  printf("Actual: %d\n\n", result);
#endif
  assert(result != 0);
}
*/
