#include "tests.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* This is a simple testing library I wrote around the assert(3) macro; I
 * looked into some other testing libraries like cmocka but most of them were
 * overkill for my needs.
 */

// assert_ints_*(): compare integers
void assert_ints_eq(const int a, const int b) { assert(a == b); }
void assert_ints_neq(const int a, const int b) { assert(a != b); }

// assert_strings_*(): compare strings via strcmp(); assumes strings are null
// terminated
void assert_strings_eq(const char* const a, const char* const b) {
  assert(strcmp(a, b) == 0);
}

void assert_strings_neq(const char* const a, const char* const b) {
  assert(strcmp(a, b) != 0);
}

// assert_<bool>(): assert truthiness / falsity of expression
void assert_true(const bool expr) { assert(expr); }
void assert_false(const bool expr) { assert(!(expr)); }

// assert_mem_*(): Compare regions of memory via memcmp()
void assert_mem_eq(const void* const obj_a, const void* const obj_b,
                   const int size) {
  assert(memcmp(obj_a, obj_b, size) == 0);
}
void assert_mem_neq(const void* const obj_a, const void* const obj_b,
                    const int size) {
  assert(memcmp(obj_a, obj_b, size) != 0);
}
