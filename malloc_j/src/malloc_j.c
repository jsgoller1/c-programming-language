#include "malloc_j.h"
#include <stdio.h>
#include <string.h>

// malloc_j(): a general purpose storage allocator; returns
// a pointer to a chunk of bytes usable for any purpose.
void *malloc_j(const size_t bytes) {
  if (bytes == 0) {
    printf("malloc_j() | warning: must allocate at least 1B (0 requested).\n");
    return NULL;
  }

  if (bytes > total_units) {
    printf(
        "malloc_j() | warning: %lu bytes exceeds max size allowed (%lu B).\n",
        bytes, total_units * unit_size);
    return NULL;
  }

  // determine how large an acceptable free chunk must be, in multiples of
  // unit_size; if we find one that's too big, we will need to split
  // it into two chunks, which must both be at least unit_size+1 in size.
  size_t units = ((bytes + unit_size - 1) / unit_size) + 1;

  // walk the list until either we come back to the start or we find a suitable
  // block
  header *p, *prev_node;
  for (prev_node = free_list, p = free_list->next; units > p->size;
       prev_node = p, p = p->next) {
    if (p == free_list && p <= prev_node) {  // <= catches 1-node list
      printf("malloc_j() | error: no suitable blocks in free list.\n");
      return NULL;
    }
  }

  // p->size is too big; create a new chunk from the tail
  // of p and return that
  if (p->size > units) {
    // allocate the tail end
    p->size = units;
    p += p->size;
    p->size = units;
  }
  // p->size == nbytes; remove from list and return
  else {
    prev_node->next = p->next;
  }

  return p + unit_size;
}

// calloc_j(): same as malloc, but creates an array of count * size length and
// all bytes to zero
void *calloc_j(const size_t size, const size_t count) {
  size_t total_bytes = size * count;
  void *space = malloc_j(total_bytes);
  if (space != NULL) {
    memset(space, 0, total_bytes);
  }
  return space;
}
