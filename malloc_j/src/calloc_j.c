#include <string.h>
#include "malloc_j.h"

void* calloc_j(const size_t size, const size_t count) {
  size_t total_bytes = size * count;
  void* space = malloc_j(total_bytes);
  memset(space, '\0', total_bytes);
  return space;
}
