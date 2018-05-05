#include "3.3.h"
#include <stdbool.h>
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
a-1 -> a-1 (no expansion for different char types)
a-A -> a-A (no expansion for different char types)
d-a -> dcba (reverse expansion)
a-c-e -> abc-e -> abcde (chained expansion)
*/

int main() {
  // basic expansion, lower case
  // abcd
  // test("a-d");

  // basic expansion, upper case
  // ABCD
  // test("A-D");

  // basic expansion, ints
  // 01234
  // test("0-4");

  // Average input
  // abcd01234ABCD
  // test("a-d0-4A-D");

  // Reverse input
  // dcba
  test("d-a");

  // Chained expansion
  // abcd....z
  test("a-k-z");

  /*
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
  */
  return 0;
}

void test(const char* const str) {
  char* expanded = expand(str, (int)strlen(str));
  printf("test(): original: %s\n", str);
  printf("test(): expanded: %s\n-------------\n", expanded);
  free(expanded);
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
        for (int k = 0; k < 11; k++) {
          printf("%c |", expanded[k]);
        }
        printf("\n");
        expansion = generate_expansion(str[i - 1], str[i + 1]);
        for (int k = 0; k < 11; k++) {
          printf("%c |", expanded[k]);
        }
        printf("\n");
        strcpy(expanded + (j - 1), expansion);
        for (int k = 0; k < 11; k++) {
          printf("%c |", expanded[k]);
        }
        printf("\n");
        j += strlen(expansion) - 1;
        i += 1;
        free(expansion);
        expansion = NULL;
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
  printf("expanded, final: %s\n", expanded);
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
