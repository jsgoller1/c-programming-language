#include <stdio.h>
#include "5.3-strlen.h"

// strlen: return length of string s
int my_strlen(char *s) {
  char *p = s;
  while (*p != '\0') {
    p++;
  }
  return (int)(p - s);
}

int main() {
  char name[] = {"Joshua Goller"};  // 13
  printf("len: %d\n", my_strlen(name));
  return 0;
}
