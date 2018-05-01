#include <2.10.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ex 2.10: Rewrite lower() to convert strings of
uppercase letters to lower, but without using if-else.
*/

int main() {
  test("JOSHUA");
  test("bob");
  test("");
  test("YoU ArE a GeNiUs!/#?");

  return 0;
}

// mylower(): converts a string to lowercase without if/else
char* mylower(const char* const str, const int len) {
  int i;
  char* lowered = (char*)malloc((unsigned long)len + 1);
  for (i = 0; i < len; i++) {
    ((str[i] >= 'A') && (str[i] <= 'Z')) ? (lowered[i] = str[i] + 32)
                                         : (lowered[i] = str[i]);
  }
  lowered[i] = '\0';
  return lowered;
}

void test(const char* const str) {
  char* lowered = mylower(str, (int)strlen(str));
  printf("%s\n", lowered);
  free(lowered);
}
