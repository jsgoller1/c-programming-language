#include "5.5-strcmp.h"
#include <stdio.h>

int strcmp_arrays(char *s, char *t) {
  int i;
  for (i = 0; s[i] == t[i]; i++) {
    if (s[i] == '\0') {
      return 0;
    }
  }
  return s[i] - t[i];
}

int strcmp_pointers(char *s, char *t) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

int main() {
  char my_name[] = {"JoshBa"};
  char your_name[] = {"JoshAd"};
  char also_my_name[] = {"JoshBa"};

  printf("comparing my_name and your_name: %d\n",
         strcmp_arrays(my_name, your_name));
  printf("comparing my_name and also_my_name: %d\n",
         strcmp_pointers(my_name, also_my_name));

  return 0;
}
