#include "5.3-strlen.h"
#include <stdio.h>

// strlen - return length of string s
int my_strlen(char *s) {
  int n;
  for (n = 0; *s != '\0'; s++) {
    n++;
  }
  return n;
}

int main() {
  char name[] = {"Joshua Goller"};  // 13
  printf("len: %d\n", my_strlen(name));
  return 0;
}
