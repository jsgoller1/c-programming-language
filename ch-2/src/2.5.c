#include <stdio.h>
#include <string.h>

#include "2.5.h"

/*
Ex 2.5: Write the function any(s1 ,s2), which returns the first location
in the string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2. (The standard library function strpbrk does
the same job but returns a pointer to the location.)
*/

int main() {
  // 1: "o" is found at 4 in string 2 and 1 in string 1 (J != j)
  test("Joshua", "Slavoj");

  // 1: "i" is in dennis, and is at 1 in Nick
  test("Nick", "Dennis");

  // -1
  test("King", "Queer");

  // -1
  test("Joshua", "");

  // -1
  test("", "Joshua");

  return 0;
}

// any(): find first occurence in s1 of a char in both s1 and s2
int any(const char* const s1, const int len1, const char* const s2,
        const int len2) {
  int i, j;
  for (i = 0; i < len1; i++) {
    for (j = 0; j < len2; j++) {
      if (s1[i] == s2[j]) {
        return i;
      }
    }
  }

  return -1;
}
void test(const char* const s1, const char* const s2) {
  const int len1 = (int)strlen(s1);
  const int len2 = (int)strlen(s2);
  const int i = any(s1, len1, s2, len2);
  if (i != -1) {
    printf("%c in %s (at %d) and %s.\n", s1[i], s1, i, s2);
  } else {
    printf("%s and %s share no characters.\n", s1, s2);
  }
}
