/*
 * CONVENTIONS
 * ===
 * - All code is in Google C/C++ style and linted via clang-format.
 * - Everything should be lower_snake_case.
 * - Every non-main function should have a single comment above the definition,
 *   starting with name(): ... and a description using its parameters.
 *  - E.g.: swap(): swaps s[i] and s[j] in s.
 * - Constants should always be #defined in UPPER_SNAKE_CASE.
 * - Every function parameter should be const (pointers and values) unless the
 *   function needs to mutate it.
 * - Comments longer than three lines should use /* ... with * on each line
 *   (like in this file), one and two liners use //.
 * - Functions that are relevant only to the file should be static; any code
 *   that is used between files should be in common.c.
 * - The order of things in each file is:
 *   - #includes
 *   - #pragmas
 *   - Problem statement, starting with Ex <chapter>.<problem>: ...
 *   - #defines
 *   - typedefs and struct definitions
 *   - static functions, such as test()
 *   - main()
 *   - Other function definitions, ordered by call order during execution
 *
 * See below for an example file (which doesn't compile since it's missing
 * headers).
 */
//-------------------------------------------------------------------------------------
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#pragma clang diagnostic ignored "-Wunused-function"

/*
 * Ex 9.1: Write a function foobaz_is_bar() that determines if a foo's baz is
 * bar
 */

#define MAX_FOO 100

typedef struct f {
  int x;
  int y;
} foo;

// test(): tests foobar()
static void test(const int a, const int b) {
  /*
   * code goes here
   */
}

int main() {
  foo mf = {1, 2};
  test(1, foobar(&mf, 3));
  return 0;
}

// foobaz_is_bar(): check if a foo's baz is bar
int foobaz_is_bar(const foo* const myfoo, const int bar) {
  if (baz(myfoo) == bar) {
    return 1;
  } else {
    return 0;
  }
}

int baz(const foo* const myfoo) {
  /*
   * code goes here
   */
  return 1;
}
