#include <string.h>
#include "malloc_j.h"

void* calloc_j(unsigned int size, unsigned int count) {
  unsigned int total_bytes = size * count;
  void* space = malloc_j(total_bytes);
  memset(space, '\0', total_bytes);
  return space;
}
