#include <stdio.h>
#include "malloc_j.h"

size_t total_mem = 0;
size_t free_mem = 0;
size_t allocated_mem = 0;
size_t bfree_mem = 0;

size_t total_chunks = 0;
size_t free_chunks = 0;
size_t allocated_chunks = 0;
size_t bfree_chunks = 0;

// display_metrics(): shows useful runtime information about
// the allocator
void* display_metrics(void) {
  display_mem();
  display_chunks();
}

// display_mem(): shows useful runtime information about
// total available memory
void* display_mem(void) {
  printf("Memory stats (B):\n");
      "* total_mem: %lu\n"
      "* free_mem: %lu\n"
      "* allocated_mem: %lu\n"
      "* bfree_mem: %lu\n\n",
      total_mem, free_mem, allocated_mem, bfree_mem);
}

// display_chunks(): shows useful runtime information about
// chunks in the free list
void* display_chunks(void) {
  printf("Chunk stats:\n");
      "* total_chunks: %lu\n"
      "* free_chunks: %lu\n"
      "* allocated_chunks: %lu\n"
      "* bfree_chunks: %lu\n\n",
      total_chunks, free_chunks, allocated_chunks, bfree_chunks);
}
