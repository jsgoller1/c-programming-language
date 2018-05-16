#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tests.h>

static void reverse_p(char* const str, const int len) {
  char *first, *last;
  char temp;

  for (first = str, last = str + len - 1; first <= last; first++, last--) {
    temp = *last;
    *last = *first;
    *first = temp;
  }
}

static void test(char* const input, const char* const expected,
                 const char* const message) {
  const int len = (int)strlen(input);
  char* copy = (char*)malloc((unsigned long)len);
  strcpy(copy, input);

  reverse_p(copy, len);
  assert_string_eq(copy, expected, "reverse", message);
  free(copy);
}

int main() {
  test("Joshua", "auhsoJ", "even input");
  test("Steve", "evetS", "odd input");
  test("a", "a", "single input");
  test("", "", "null input");
  printf("5.6: PASS!\n");
  return 0;
}
