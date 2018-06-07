#include "malloc_j.h"

// free_j(): put block ap in free list
int free_j(void *chunk) {
  header *ll_node, *p;

  ll_node = (header *)chunk - 1;  // point to block header

  if (ll_node->size <= 1) {
    printf("free_j() | warning: cannot add block with size < 1 to list.\n");
    return -1;
  }

  /* find insertion point. There are three possibilities:
    1. chunk's address is before list head; ll_node should be added and become
    free_list.
    2. chunk's address is after list tail; ll_node should become the tail.
    3. chunk's addres is between list head and tail; find the correct place and
    insert it.
  */

  // handle case 1
  if (ll_node < free_list) {
    ll_node.next = free_list;
    free_list = ll_node;
    return;
  }

  // handle cases 2 and 3; we will either find the right place
  // or reach the end of the list.
  for (p = free_list; p < p->next; p = p->next) {
    if (p < ll_node && ll_node < p->next) {
      break;
    }
  }

  // if contiguous as [ ll_node | p ], join as one block preserving ll_node
  if (ll_node + ll_node->size == p->next) {
    ll_node->size += p->next->size + sizeof(header);
    ll_node->next = p->next->next;
    p->next = ll_node;
  }

  // if contiguous as [ p | ll_node ], join as one block preserving p
  else if (p + p->size == ll_node) {
    p->size += ll_node->size + sizeof(header);
    p->next = ll_node->next;
  }

  // otherwise, just append.
  else {
    ll_node->next = p->next;
    p->next = ll_node;
  }
  // TODO: metrics here
  return 0;
}

// bfree(): add n bytes starting at p to the free list. Because we
// store metadata in each block and do not store empty blocks, n must be at
// least sizeof(header) + 1.
int bfree(void *p, size_t n) {
  if (n < sizeof(header) + 1) {
    printf(
        "bfree() | warning: tried bfree() for %lu bytes, cannot add block with "
        "size < %lu bytes to list.\n",
        n, sizeof(header) + 1);
    return -1;
  }
  if (free(p + sizeof(header)) == -1) {
    return -1;
  }
  // TODO: metrics here
  return 0;
}
