#include <stdio.h>

int mylower(char c);

int main() {
  int i = 0;
  char name[] = {"JOSHUA GOLLER"};
  for (i = 0; i < 13; i++) {
    printf("%d, %d, %c\n", i, mylower(name[i]), mylower(name[i]));
  }
  printf("\n");
  return 0;
}

/* myatoi(): converts s to integer */
int mylower(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  } else {
    return c;
  }
}