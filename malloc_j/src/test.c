#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc_j.h"

int main() {
  if (init() == -1) {
    return -1;
  }
  // printf("bfree() test\n");
  // char* baz = malloc((unsigned long)1000);
  // bfree((void*)baz, 1000);

  char* bar = calloc_j(10, 4);
  if (bar == NULL) {
    return -1;
  }
  for (int i = 0; i < 38; i++) {
    bar[i] = 'A';
  }
  bar[39] = '\0';
  printf("calloc_j test: %s\n", bar);
  free_j(bar);

  char* foo = malloc_j(27);
  strcpy(foo, "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0");
  if (foo == NULL) {
    return -1;
  }
  printf("malloc_j test: %s\n", foo);
  free_j(foo);

  cleanup();
  return 0;
}
