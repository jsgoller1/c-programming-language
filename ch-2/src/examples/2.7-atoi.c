#include <stdio.h>

int myatoi(char s[]);

int main() {
  char name[2] = {"10"};
  printf("%d\n", myatoi(name));
  return 0;
}

/* myatoi(): converts s to integer */
int myatoi(char s[]) {
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
    n = 10 * n + (s[i] - '0');
  }

  return n;
}