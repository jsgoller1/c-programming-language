#include "malloc_j.h"
#include <stdio.h>

// malloc_j(): a general purpose storage allocator; returns
// a pointer to a chunk of bytes usable for any purpose.
void *malloc_j(size_t nbytes) {
  header *p, *prevp;
  unsigned nunits;
  if (nbytes == 0) {
    printf("malloc_j() | warning: 0 bytes requested.");
    return NULL;
  }

  if (nbytes > INIT_PAGE_SIZE) {
    printf("malloc_j() | warning: %d bytes exceeds max size.\n", nbytes);
    return NULL;
  }
  // printf("malloc_j() | %d bytes requested.\n", nbytes);

  // ensure we align on word boundaries; sizeof(header) is 16
  nunits = (nbytes + sizeof(header) - 1) / sizeof(header) + 1;
  // printf("malloc_j() | %d nunits required.\n", nunits);

  if ((prevp = freep) == NULL) {  // no free list yet
    base.s.next = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.next;; prevp = p, p = p->s.next) {
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
      freep = prevp;
      // printf("malloc_j() | actual returned block size (id: %d): %d units\n",
      //       p->s.block_id, p->s.size);
      return (void *)(p + 1);
    }
    if (p == freep) {  // wrapped around free list
      printf("malloc_j() | warning: space exhausted.\n");
      return NULL;  // none left
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
