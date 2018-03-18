#include <stdio.h>
#include <string.h>

void reverse(char s[]);

/* reverse: reverse string s in place */
int main() {
  char name[] = {"Joshua"};
  reverse(name);
  printf("%s\n", name);

  return 0;
}

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}