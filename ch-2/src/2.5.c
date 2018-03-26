#include <stdio.h>

/*
Write the function any(s1 ,s2), which returns the first location
in the string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2. (The standard library function strpbrk does
the same job but returns a pointer to the location.)
*/

int any(char s1[], char s2[]);

int main() {
  char string1[] = {"Joshua"};
  char string2[] = {"Slavoj"};
  // 1: "o" is found at 4 in string 2 and 1 in string 1 (J != j)
  printf("%d\n", any(string1, string2));

  char string3[] = {"Joshua"};
  char string4[] = {""};
  // -1
  printf("%d\n", any(string3, string4));

  char string5[] = {""};
  char string6[] = {"Slavoj"};
  // -1
  printf("%d\n", any(string5, string6));

  char string7[] = {"Nick"};
  char string8[] = {"Dennis"};
  // 1
  printf("%d\n", any(string7, string8));

  return 0;
}

int any(char s1[], char s2[]) {
  int i, j;
  for (i = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        return i;
      }
    }
  }

  return -1;
}