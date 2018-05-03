#include "3.3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*
Exercise 3-3. Write a function expand(s1, s2) that expands shorthand
notations like a-z in the string s1 into the equivalent complete list abc...xyz
in s2. Allow for letters of either case and digits, and be prepared to handle
cases like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
taken literally.
----
For this, I'm assuming that:
(no expansion for different chars)
a-1 -> a-1,
a-A -> a-A, etc.
d-a -> dcba (reverse expansion)
a-c-e -> abc-e -> abcde (chained expansion)
*/

int main() {
  // basic expansion, lower case
  // abcd
  test("a-d");

  // basic expansion, upper case
  // ABCD
  test("A-D");

  // basic expansion, ints
  // 01234
  test("0-4");

  // Average input
  // abcd01234ABCD
  test("a-d0-4A-D");

  // Reverse input
  // dcba
  test("d-a");

  // null input
  // ""
  test("");

  // edge cases, all of which should
  // print their input
  test("-");
  test("-a-");
  test("a--a");
  test("abcd");
  test("1-a");
  return 0;
}

void test(const char* const str) {
  char* expanded = expand(str, (int)strlen(str));
  printf("original: %s\n", str);
  printf("expanded: %s\n\n", expanded);
  free(expanded);
}

char* expand(const char* const str, const int len) {
  int i;   // s1 index
  int j;   // s2 index
  char k;  // temp var for expansion

  // We will assume that expand() will never
  // expand to more than 1000 characters,
  // which is not at all a reasonable assumption.
  char* expanded = (char*)malloc((unsigned long)get_expanded_size(str) + 1);

  // go through the string until we find a '-'
  for (i = 0, j = 0; i < len; i++) {
    // check if the chars left and right of it are within bounds
    if (str[i] == '-') {
      // if so, determine if specificed range is of valid "types" (upper, lower,
      // or int, both bounds are the same "type")
      if (is_valid_range(str[i - 1], str[i + 1])) {
        range_expansion();
      } else {
        // invalid range bounds, copy the '-' mark
        expanded[j++] = str[i];
      }
    } else {
      // either left or right is outside of s1 or the s[i] != '-'; copy
      // s[i]
      expanded[j++] = str[i];
    }
  }
  expanded[j] = '\0';
  return expanded;
}

int is_valid_range(char a, char b) {
  int type_a, type_b;
  type_a = get_char_type(a);
  type_b = get_char_type(b);

  return ((type_a == type_b) && (type_a != -1));
}

void valid_bounds() { (str[i] == '-') && ((i - 1 >= 0) && (i + 1 < len)) }

void range_expansion() {
  // given that they're the same type, determine if they're ascending or
  // descending
  if (str[i - 1] < str[i + 1]) {
    // for ascending, expand by incrementing; remember
    // the left bound is already in s2 from the previous
    // iteration, so skip it.
    for (k = (str[i - 1] + 1); k <= str[i + 1]; k++) {
      expanded[j] = k;
      j++;
    }
    i++;  // in a-c, don't evaluate c after evaluating -;
  } else if (str[i - 1] > str[i + 1]) {
    // for descending, expand by looping down; remember
    // the left bound is already the first correct char
    for (k = (str[i - 1] - 1); k >= str[i + 1]; k--) {
      expanded[j] = k;
      j++;
    }
    i++;  // in c-a, don't evaluate a after evaluating -;

  } else  // they're equal, just copy the character;
  {
    expanded[j] = str[i];
    j++;
  }
}

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

int get_expanded_size(const char* const str) { return 0; }

int is_upper(const char a) { return (a >= 'A') && (a <= 'Z'); }

int is_lower(const char a) { return (a >= 'a') && (a <= 'z'); }

int is_int(const char a) { return (a >= '0') && (a <= '9'); }
