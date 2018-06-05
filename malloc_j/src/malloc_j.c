#include "malloc_j.h"
#include <stdio.h>

// malloc_j(): a general purpose storage allocator
void *malloc_j(unsigned int nbytes) {
  Header *p, *prevp;
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

  // ensure we align on word boundaries; sizeof(Header) is 16
  nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
  // printf("malloc_j() | %d nunits required.\n", nunits);

  if ((prevp = freep) == NULL) {  // no free list yet
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {
    // printf("malloc_j() | examining block of size: %d\n", nunits);
    if (p->s.size >= nunits) {  // big enough
      // printf("malloc_j() | found block of size: %d\n", nunits);
      if (p->s.size == nunits) {  // exact
        prevp->s.ptr = p->s.ptr;
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
      if ((p = morecore(nunits)) == NULL) {
        printf("malloc_j() | warning: space exhausted.\n");
        return NULL;  // none left
      }
    }
  }
}
