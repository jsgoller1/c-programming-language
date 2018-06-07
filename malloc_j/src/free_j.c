#include "malloc_j.h"

// free_j(): put block ap in free list
void free_j(void *chunk) {
  header *ll_node, *p;

  ll_node = (header *)chunk - 1;  // point to block header

  if (ll_node->size <= 1) {
    printf("free_j() | warning: cannot add block with size < 1 to list.\n");
    return;
  }

  // find insertion point (?)
  // start at list head, move through list while ll_node isn't in the list
  for (p = freep; !(ll_node > p && ll_node < p->ptr); p = p->ptr) {
    if (p >= p->ptr && (ll_node > p || ll_node < p->ptr)) {
      break;  // freed block at start or end of area
    }
  }

  // if contiguous as [ ll_node | p ], join as one block preserving ll_node
  if (ll_node + ll_node->size == p->ptr) {
    ll_node->size += p->ptr->size;  // add next block's size
    ll_node->ptr = p->ptr->ptr;     // make ll_node's next the next's next.
  } else {
    ll_node->ptr = p->ptr;  // append instead of joining
  }

  // if contiguous as [ p | ll_node ], join as one block preserving p
  if (p + p->size == ll_node) {
    p->size += ll_node->size;
    p->ptr = ll_node->ptr;
  } else {
    p->ptr = ll_node;
  }
  freep = p;
}

void bfree(void *p, int n) {
  (void)p;
  (void)n;
}
