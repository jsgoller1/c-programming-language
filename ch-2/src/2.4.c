#include "2.4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ex 2.4: Write an alternate version of squeeze(s1 ,s2) that deletes
each character in s1 that matches any character in the string s2.
*/

int main() {
  // o oo ases oo!
  test("dog food tastes good!", "dgft");

  // dg fd tsts gd
  test("dog food tastes good!", "oae");

  // dog food tastes good!
  test("dog food tastes good!", "jqx");

  // dog food tastes good!
  test("dog food tastes good!", "");

  // ""
  test("", "dog food tastes good!");

  return 0;
}

// squeeze(): delete all chars from s1 that are present in s2; callee
// is responsible for freeing the returned string.
char* squeeze(char* const s1, const int len1, const char* const s2,
              const int len2) {
  int i, j;
  // the squeezed string will never be larger than the original,
  // so while possibly wasteful, using len1 is sufficient
  char* squeezed = (char*)malloc((unsigned long)len1 + 1);

  for (i = 0, j = 0; i < len1; i++) {
    if (charmatch(s1[i], s2, len2) == -1) {
      squeezed[j] = s1[i];
      j++;
    }
  }

  squeezed[i] = '\0';
  return squeezed;
}

// charmatch(): returns index of c in str1, or -1 if not found.
int charmatch(const char c, const char* const str, const int len) {
  int i;
  for (i = 0; i < len; i++) {
    if (str[i] == c) {
      return i;
    }
  }
  return -1;
}

void test(char* const str1, const char* const str2) {
  printf("%s - removing '%s': ", str1, str2);
  int len1 = (int)strlen(str1);
  int len2 = (int)strlen(str2);
  char* squeezed = squeeze(str1, len1, str2, len2);
  printf("%s\n", squeezed);
  free(squeezed);
}
