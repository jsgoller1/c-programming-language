#include "5.5-strcpy.h"
#include <stdio.h>

// strcpy: copy t to s, array subscript version
void strcpy_arrays(char *s, char *t) {
  int i;
  i = 0;
  while ((t[i] = s[i]) != '\0') {
    i++;
  }
}

// strcpy: copy t to s, pointer version
void strcpy_pointers(char *s, char *t) {
  while ((*t = *s) != '\0') {
    s++;
    t++;
  }
}

// strcpy: copy t to s, pointer version
void strcpy_pointers2(char *s, char *t) {
  while ((*t++ = *s++) != '\0') {
    // no-op
  }
}

int main() {
  char my_name[] = {"Joshua Goller"};  // 13
  char name1[14];
  char name2[14];
  char name3[14];
  strcpy_arrays(&my_name[0], &name1[0]);
  strcpy_pointers(&my_name[0], &name2[0]);
  strcpy_pointers2(&my_name[0], &name3[0]);

  printf("name1: %s\n", name1);
  printf("name2: %s\n", name2);
  printf("name3: %s\n", name3);

  return 0;
}
