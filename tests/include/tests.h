#include <stdbool.h>

void assert_int_eq(const int actual, const int expected,
                   const char* const func_name, const char* const message);
void assert_int_neq(const int actual, const int expected,
                    const char* const func_name, const char* const message);

void assert_double_eq(const double actual, const double expected,
                      const double error, const char* const func_name,
                      const char* const message);
void assert_double_neq(const double actual, const double expected,
                       const double error, const char* const func_name,
                       const char* const message);

void assert_string_eq(const char* const actual, const char* const expected,
                      const char* const func_name, const char* const message);
void assert_string_neq(const char* const actual, const char* const expected,
                       const char* const func_name, const char* const message);

void assert_true(const bool expr, const char* const func_name,
                 const char* const message);
void assert_false(const bool expr, const char* const func_name,
                  const char* const message);

void assert_mem_eq(const void* const actual, const void* const expected,
                   const int size, const char* const func_name,
                   const char* const message);
void assert_mem_neq(const void* const actual, const void* const expected,
                    const int size, const char* const func_name,
                    const char* const message);
