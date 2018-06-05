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
