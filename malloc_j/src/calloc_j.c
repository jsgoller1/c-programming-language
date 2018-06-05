#include <string.h>
#include "malloc_j.h"

void* calloc_j(const unsigned int size, const unsigned int count) {
  unsigned int total_bytes = size * count;
  void* space = malloc_j(total_bytes);
  memset(space, '\0', total_bytes);
  return space;
}
