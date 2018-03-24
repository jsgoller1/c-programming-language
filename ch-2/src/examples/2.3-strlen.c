#include <stdio.h>

int mystrlen(char s[]);

int main() {
  char name[] = {"Joshua"};
  printf("%d\n", mystrlen(name));
  return 0;
}

int mystrlen(char s[]) {
  int i;

  i = 0;
  while (s[i] != '\0') {
    ++i;
  }

  return i;
}
