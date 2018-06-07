#include "malloc_j.h"
#include <stdio.h>

// malloc_j(): a general purpose storage allocator; returns
// a pointer to a chunk of bytes usable for any purpose.
void *malloc_j(size_t nbytes) {
  if (nbytes == 0) {
    printf("malloc_j() | warning: must allocate at least 1B (0 requested).\n");
    return NULL;
  }

  if (nbytes > INIT_PAGE_SIZE - sizeof(header)) {
    printf("malloc_j() | warning: %d bytes exceeds max size allowed (%lu B).\n",
           nbytes, INIT_PAGE_SIZE - sizeof(header));
    return NULL;
  }
  // printf("malloc_j() | %d bytes requested.\n", nbytes);

  /*
  // TODO: Do we need to align?
  // ensure we align on word boundaries; sizeof(header) is 16
  nunits = (nbytes + sizeof(header) - 1) / sizeof(header) + 1;
  printf("malloc_j() | %d nunits required.\n", nunits);
  */

  // walk the list until either we come back to the start or we find a suitable
  // block
  header *p, *prev_node;
  for (prev_node = free_list, p = free_list->next; nbytes > p->size;
       prevp = p, p = p->next) {
    if (p == free_list && p < prev_node) {
      printf("malloc_j() | error: no suitable blocks in free list.\n");
      return NULL;
    }
  }

  // p->size is too big; slice up the block and return;
  if (p->size > nbytes) {
  }
  // p->size == nbytes; remove from list and return
  else {
    prev_node->next = p->next;
    return p + sizeof(header);
  }

  // printf("malloc_j() | examining block of size: %d\n", nunits);
  if (p->s.size >= nunits) {  // big enough
    // printf("malloc_j() | found block of size: %d\n", nunits);
    if (p->s.size == nunits) {  // exact
      prevp->s.next = p->s.next;
    } else {  // allocate tail end
      p->s.size -= nunits;
      p += p->s.size;
      p->s.size = nunits;
    }
  }
}

// calloc_j(): same as malloc, but creates an array of count * size length and
// all bytes to zero
void *calloc_j(const size_t size, const size_t count) {
  size_t total_bytes = size * count;
  void *space = malloc_j(total_bytes);
  memset(space, 0, total_bytes);
  return space;
}
