#include "3.3.h"
#include <assert.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
// -- cmocka has to be included last because it relies on stdlib headers --
#include <cmocka.h>

/*
Exercise 3-3. Write a function expand(s1, s2) that expands shorthand
notations like a-z in the string s1 into the equivalent complete list abc...xyz
in s2. Allow for letters of either case and digits, and be prepared to handle
cases like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
taken literally.
----
For this, I'm assuming that:
a-1 -> a-1 (no expansion for different char types)
a-A -> a-A (no expansion for different char types)
d-a -> dcba (reverse expansion)
a-c-e -> abc-e -> abcde (chained expansion)
*/

static void test_basic_expansion_lower(void** state) {
  (void)state;
  char base[] = "a-d";
  char expected[] = "abcd";
  char* actual = expand(base, (int)strlen(base));
  assert_string_equal(actual, expected);
  free(actual);
}

static void test_basic_expansion_upper(void** state) {
  (void)state;
  char base[] = "A-D";
  char expected[] = "ABCD";
  char* actual = expand(base, (int)strlen(base));
  assert_string_equal(actual, expected);
  free(actual);
}

static void test_basic_expansion_ints(void** state) {
  (void)state;
  char base[] = "0-4";
  char expected[] = "01234";
  char* actual = expand(base, (int)strlen(base));
  assert_string_equal(actual, expected);
  free(actual);
}

static void test_normal_input(void** state) {
  (void)state;
  char base[] = "a-d0-4A-D";
  char expected[] = "abcd01234ABCD";
  char* actual = expand(base, (int)strlen(base));
  assert_string_equal(actual, expected);
  free(actual);
}

static void test_chained_expansion(void** state) {
  (void)state;
  char base[] = "a-k-z";
  char expected[] = "abcdefghijklmnopqrstuvwxyz";
  char* actual = expand(base, (int)strlen(base));
  assert_string_equal(actual, expected);
  free(actual);
}

static void test_reverse_expansion(void** state) {
  (void)state;
  char base[] = "5-0";
  char expected[] = "543210";
  char* actual = expand(base, (int)strlen(base));
  assert_string_equal(actual, expected);
  free(actual);
}

static void test_edge_cases_self_print(void** state) {
  (void)state;
  char* base[] = {"", "-", "-a-", "a--a", "abcd", "1-a"};
  for (int i = 0; i < 5; i++) {
    char* actual = expand(base[i], (int)strlen(base[i]));
    assert_string_equal(actual, base[i]);
    free(actual);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_basic_expansion_lower),
      cmocka_unit_test(test_basic_expansion_upper),
      cmocka_unit_test(test_basic_expansion_ints),
      cmocka_unit_test(test_normal_input),
      cmocka_unit_test(test_chained_expansion),
      cmocka_unit_test(test_reverse_expansion),
      cmocka_unit_test(test_edge_cases_self_print),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

// expand(): performs expansion per the instructions
char* expand(const char* const str, const int len) {
  int i;            // s1 index
  int j;            // s2 index
  char* expansion;  // temp var for expansion

  // We will assume that expand() will never
  // expand to more than 1000 characters,
  // which is not at all a reasonable assumption.
  char* expanded = (char*)malloc((unsigned long)1000);
  memset(expanded, '\0', 1000);

  // Copy chars from str to expanded until we encounter a -
  for (i = 0, j = 0; i < len; i++) {
    // printf("%c\n", str[i]);
    if (str[i] == '-') {
      if (valid_expansion(str, i, len)) {
        /*
        The - represents a valid expansion; generate
        the expansion, and append it to the expanded string;
        the expanded string already has str[i-1], so overwrite
        it with \0 given that strcat() needs a null to determine
        where to append.
        */
        expansion = generate_expansion(str[i - 1], str[i + 1]);
        strcpy(expanded + (j - 1), expansion);
        j += strlen(expansion) - 1;
        i += 1;
        free(expansion);
      } else {
        // the - doesn't represent a valid
        // expansion, so just copy it
        expanded[j++] = str[i];
      }
    } else {
      // not a -
      expanded[j++] = str[i];
    }
  }

  expanded[j] = '\0';
  return expanded;
}

// valid_expansion(): tests if a three character expression with "-"
// in the middle represents a valid expansion expression
bool valid_expansion(const char* const str, const int i, const int len) {
  int left = get_char_type(str[i + 1]);
  int right = get_char_type(str[i - 1]);
  bool is_valid = true;

  // the char is actually a -
  is_valid &= (str[i] == '-');

  // left and right bounds are not outside the string
  is_valid &= (i - 1 >= 0) && (i + 1 < len);

  // we don't try to expand a-5 or 6-q
  is_valid &= (left == right);

  // catch edge case where both a and b are invalid, like ?-#
  is_valid &= (left != -1);

  return is_valid;
}

// generate_expansion(): given that "a-b" is a valid
// expansion, generate the expansion and return it. The
// callee is responsible for freeing the returned char*.
char* generate_expansion(const char a, const char b) {
  char* expansion = NULL;
  int i = 0;

  if (a < b) {
    expansion = (char*)malloc((unsigned long)(b - a) + 1);
    for (i = 0; a + i <= b; i++) {
      expansion[i] = a + (char)i;
    }
  } else if (a > b) {
    expansion = (char*)malloc((unsigned long)(a - b) + 1);
    for (i = 0; a - i >= b; i++) {
      expansion[i] = a - (char)i;
    }
  } else {
    // they're equal, so the "expansion" is just the character
    expansion = (char*)malloc((unsigned long)2);
    expansion[i++] = a;
  }
  expansion[i] = '\0';

  return expansion;
}

// get_char_type(): determines if a is an int, lowercase or uppercase char
int get_char_type(const char a) {
  if (is_upper(a)) {
    return 0;
  } else if (is_lower(a)) {
    return 1;
  } else if (is_int(a)) {
    return 2;
  } else {
    return -1;
  }
}

int is_upper(const char a) { return (a >= 'A') && (a <= 'Z'); }

int is_lower(const char a) { return (a >= 'a') && (a <= 'z'); }

int is_int(const char a) { return (a >= '0') && (a <= '9'); }
