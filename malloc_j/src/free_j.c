#include "malloc_j.h"

// free_j(): put block ap in free list
void free_j(void *ap) {
  Header *bp, *p;

  bp = (Header *)ap - 1;  // point to block header

  if (bp->s.size <= 1) {
    printf("free_j() | warning: cannot add block with size < 1 to list.\n");
    return;
  }

  // find insertion point (?)
  // start at list head, move through list while bp isn't in the list
  for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
      break;  // freed block at start or end of area
    }
  }

  // if contiguous as [ bp | p ], join as one block preserving bp
  if (bp + bp->s.size == p->s.ptr) {
    bp->s.size += p->s.ptr->s.size;  // add next block's size
    bp->s.ptr = p->s.ptr->s.ptr;     // make bp's next the next's next.
  } else {
    bp->s.ptr = p->s.ptr;  // append instead of joining
  }

  // if contiguous as [ p | bp ], join as one block preserving p
  if (p + p->s.size == bp) {
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else {
    p->s.ptr = bp;
  }
  freep = p;
}

/*
bfree(): adds an arbitrary block of memory to the list.

If implemented correctly, I should be able to use an array allocated
by stdlib/malloc() or an array on the stack in main and bfree() it successfully.

1) We must add the entire block at p to the list.
  * We cannot use part of it for the header.
2) We cannot make any assumptions about the bytes before or after the block, so
we cannot modify them.
  * We cannot create the header in the first sizeof(Header) bytes before p.
3) Pointers to the original data must still be able to successfully dereference
it.
  * We cannot memcpy() n bytes from p into a block obtained by malloc_j()

---
Instead, do not force the headers to be contiguous to the memory they represent;
add a "void* data" pointer to the header that points to the chunk obtained from
jbrk(). This way, we can just have data point to the arbitrary memory.

Joining contiguous blocks can be done by comparing to bp->s.data instead of bp.
*/
void bfree(void *p, int n) {
  (void)p;
  (void)n;
}
