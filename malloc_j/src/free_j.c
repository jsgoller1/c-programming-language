#include <stdbool.h>
#include "malloc_j.h"

static void merge_chunks(header *first, header *second,
                         bool preserve_first_next) {
  first->size += second->size + sizeof(header);
  if (!(preserve_first_next)) {
    first->next = second->next;
  }
}

// free_j(): insert a chunk into the free list
int free_j(void *const chunk) {
  header *p;
  header *const ll_node =
      (header *)chunk - sizeof(header);  // point to block header

  if (ll_node->size <= 1) {
    printf(
        "free_j() | warning: cannot add block with size < 1 to list (attempted "
        "%lu).\n",
        ll_node->size);
    return -1;
  }

  /* find insertion point. There are three possibilities:
    1. chunk's address is before list head; ll_node is prepended, and ll_node
    becomes become free_list.
    2. chunk's address is after list tail; ll_node should be appended to the
    list.
    3. chunk's address is between list head and tail; find the correct place and
    insert it.
  */

  // handle case 1, merging if necessary
  if (ll_node < free_list) {
    if (ll_node + ll_node->size == free_list) {
      merge_chunks(ll_node, free_list, false);
    } else {
      ll_node->next = free_list;
    }
    free_list = ll_node;
  }

  // handle cases 2 and 3
  p = free_list;
  while ((p < ll_node) && (p < p->next)) {
    if (p == ll_node) {
      printf("free_j() | warning: double free.\n");
    }
    if (ll_node < p->next) {
      // ll_node falls between p and p->next
      break;
    };
    p = p->next;
  }

  // contiguous as [ ll_node | p->next ], join blocks and keep ll_node
  if (ll_node + ll_node->size == p->next) {
    merge_chunks(ll_node, p->next, false);
    p->next = ll_node;
  }

  // contiguous as [ p | ll_node ], join blocks and keep p
  else if (p + p->size == ll_node) {
    merge_chunks(p, ll_node, true);
  }

  // non-contiguous; append ll_node
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
int bfree(void *const p, const size_t n) {
  if (n < sizeof(header) * 2) {
    printf(
        "bfree() | warning: tried bfree() for %lu bytes, cannot add block with "
        "size < %lu bytes to list.\n",
        n, sizeof(header) * 2);
    return -1;
  }
  header *chunk = (header *)p;
  size_t usable_bytes = n - sizeof(header) - (n % sizeof(header));
  chunk->size = usable_bytes / sizeof(header);

  if (free_j(chunk + sizeof(header)) == -1) {
    return -1;
  }
  // TODO: metrics here
  return 0;
}
