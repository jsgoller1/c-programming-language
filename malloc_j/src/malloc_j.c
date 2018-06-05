#include "malloc_j.h"
#include <stdio.h>

// malloc_j(): a general purpose storage allocator
void *malloc_j(unsigned int nbytes) {
  Header *p, *prevp;
  unsigned nunits;
  printf("malloc_j() | allocating %d bytes.\n", nbytes);

  nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
  if ((prevp = freep) == NULL) {  // no free list yet
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {
    if (p->s.size >= nunits) {    // big enough
      if (p->s.size == nunits) {  // exact
        prevp->s.ptr = p->s.ptr;
      } else {  // allocate tail end
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }
      freep = prevp;
      return (void *)(p + 1);
    }
    if (p == freep) {  // wrapped around free list
      if ((p = morecore(nunits)) == NULL) {
        return NULL;  // none left
      }
    }
  }
}
