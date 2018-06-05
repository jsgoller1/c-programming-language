#include <stdio.h>
#include <string.h>
#include "malloc_j.h"

int main() {
  init();
  char* foo = malloc_j(11);
  strcpy(foo, "0123456789");
  foo[10] = '\0';
  printf("%s\n", foo);
  cleanup();
  return 0;
}
