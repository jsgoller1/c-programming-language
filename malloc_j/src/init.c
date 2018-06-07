#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "common.h"
#include "malloc_j.h"

header* free_list = NULL;  // start of free list
void* init_page = NULL;

// init(): create first item in the free list by getting a massive page from
// mmap()
int init(void) {
  size_t size = (INIT_PAGE_SIZE < (sizeof(header) * 2)) ? (sizeof(header) * 2)
                                                        : INIT_PAGE_SIZE;

  if ((init_page = mmap(NULL, size, PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED) {
    char* err_desc = strerror(errno);
    printf("Couldn't allocate initial page: %s.\n", err_desc);
    return -1;
  }

  // Round the size of the initial chunk down to the nearest unit, remove one
  // unit for the header, and set the size in terms of units. Remainder bytes
  // are lost.
  header* init_block = (header*)init_page;
  size_t usable_bytes = size - sizeof(header) - (size % sizeof(header));
  init_block->size = usable_bytes / sizeof(header);
  init_block->next = init_block;
  free_list = init_block;
  printf("init() | init_page initialized:\n");
  // display_metrics();
  return 0;
}

int cleanup(void) {
  if (munmap(init_page, INIT_PAGE_SIZE) == -1) {
    char* err_desc = strerror(errno);
    printf("Couldn't unmap initial page: %s.\n", err_desc);
    return -1;
  }
  printf("cleanup() | Unmapped initial page.\n");
  return 0;
}
