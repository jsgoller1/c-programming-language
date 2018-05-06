#include <stdbool.h>

void assert_ints_eq(const int a, const int b) { assert(a == b); }
void assert_ints_neq(const int a, const int b) { assert(a != b); }

void assert_strings_eq(const char* const a, const char* const b);
void assert_strings_neq(const char* const a, const char* const b);

void assert_true(const bool expr);
void assert_false(const bool expr);

void assert_mem_eq(const void* const obj_a, const void* const obj_b,
                   const int size);
void assert_mem_neq(const void* const obj_a, const void* const obj_b,
                    const int size);
