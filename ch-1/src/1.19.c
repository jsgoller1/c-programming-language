#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "1.19.h"
#include "common.h"
#include "tests.h"

/*
 * Ex 1.19: Write a function reverse(s) that reverses the character
 * string s. Use it to write a program that reverses its input a line
 * at a time.
 */

static void test(const char* const str, const char* const expected,
                 const char* const message) {
  const int len = (int)strlen(str);
  char* actual = (char*)malloc((unsigned long)len + 1);
  strcpy(actual, str);
  reverse(actual, len);
  assert_string_eq(actual, expected, "reverse", message);
  free(actual);
}

int main() {
  printf("1.19: Running tests...\n");
  test("Joshua", "auhsoJ", "expected input");
  test("", "", "empty input");
  test("a", "a", "single char");
  printf("1.19: PASS!\n");

  return 0;
}

// swap(): exchange string[a] with string[b]
void swap(char* const string, const int a, const int b) {
  char temp;
  temp = string[a];
  string[a] = string[b];
  string[b] = temp;
}
