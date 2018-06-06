#include <stdio.h>
#include <string.h>
#include "malloc_j.h"

int main() {
  init();
  char* foo = malloc_j(200 * MiB);
  printf("Writing first string.\n");
  strcpy(foo, "ABCDEFGHIJ");
  foo[10] = '\0';
  char* bar = malloc_j(200 * MiB);
  strcpy(bar, "KLMNOPQRST");
  bar[10] = '\0';
  char* baz = calloc_j(1 * MiB, 99);
  strcpy(baz, "UVWXYZ");
  baz[10] = '\0';
  printf("%s%s%s\n", foo, bar, baz);
  cleanup();
  return 0;
}
