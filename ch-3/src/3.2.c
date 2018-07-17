#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "3.2.h"
#include "common.h"

/*
Ex 3.2: Write a function escape(s, t) that converts characters like
newline and tab into visible escape sequences like \n and \t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters.
*/

int main() {
  test("a\nb\nc\td\n\te\n");
  test("");
  return 0;
}

void test(const char* const str) {
  printf("Original: %s\n", str);

  char* escaped = escape(str, (int)strlen(str));
  printf("Escaped: %s\n", escaped);
  free(escaped);

  char* unescaped = unescape(str, (int)strlen(str));
  printf("Unescaped: %s\n", unescaped);
  free(unescaped);

  printf("----------------------------------------\n");
}

char* escape(const char* const str, const int len) {
  int i, j;

  /*
  if every char in the string is an escape char,
  the returned string will be twice as long and
  will require a null terminator.
  */
  char* escaped = (char*)malloc((unsigned long)(len * 2) + 1);

  for (i = 0, j = 0; i < len; i++) {
    switch (str[i]) {
      case '\n':
        escaped[j++] = '\\';
        escaped[j++] = 'n';
        break;
      case '\t':
        escaped[j++] = '\\';
        escaped[j++] = 't';
        break;
      default:
        escaped[j++] = str[i];
        break;
    }
  }

  escaped[j] = '\0';
  return escaped;
}

char* unescape(const char* const str, const int len) {
  int i, j;

  /*
  if every char in the string is an escaped char,
  the returned string will be half as long and
  will require a null terminator.
  */
  char* unescaped = (char*)malloc((unsigned long)(len * 2) + 1);

  for (i = 0, j = 0; i < len; i++) {
    unescaped[j++] = str[i];
    if (str[i] == '\\') {
      switch (str[++i]) {
        case 'n':
          unescaped[j++] = '\n';
          break;
        case 't':
          unescaped[j++] = '\n';
          break;
        default:
          unescaped[j++] = str[i];
          break;
      }
    }
  }
  unescaped[j] = '\0';
  return unescaped;
}
