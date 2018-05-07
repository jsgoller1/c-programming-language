#include <stdbool.h>

void assert_int_eq(const int a, const int b);
void assert_int_neq(const int a, const int b);

void assert_double_eq(const double a, const double b, const double error);
void assert_double_neq(const double a, const double b, const double error);

void assert_string_eq(const char* const a, const char* const b);
void assert_string_neq(const char* const a, const char* const b);

void assert_true(const bool expr);
void assert_false(const bool expr);

void assert_mem_eq(const void* const obj_a, const void* const obj_b,
                   const int size);
void assert_mem_neq(const void* const obj_a, const void* const obj_b,
                    const int size);
