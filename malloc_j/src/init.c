#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "common.h"
#include "malloc_j.h"

header* free_list = NULL;  // start of free list
void* init_page = NULL;
size_t total_units = 0;
static size_t actual_page_size = 0;

// init(): create first item in the free list by getting a massive page from
// mmap()
int init(const size_t desired_page_size) {
  actual_page_size = (desired_page_size < (unit_size * 2)) ? (unit_size * 2)
                                                           : desired_page_size;

  if ((init_page = mmap(NULL, actual_page_size, PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED) {
    char* err_desc = strerror(errno);
    printf("Couldn't allocate initial page: %s.\n", err_desc);
    return -1;
  }

  // Round the size of the initial chunk down to the nearest unit, remove one
  // unit for the header, and set the size in terms of units. Remainder bytes
  // are lost.
  free_list = initialize_new_chunk(init_page, actual_page_size);
  total_units = (actual_page_size / unit_size) - 1;
  printf("init() | init_page initialized.\n");
  return 0;
}

int cleanup(void) {
  if (munmap(init_page, actual_page_size) == -1) {
    char* err_desc = strerror(errno);
    printf("Couldn't unmap initial page: %s.\n", err_desc);
    return -1;
  }
  printf("cleanup() | Unmapped initial page.\n");
  return 0;
}

// initialize_new_chunk(): Set up an arbitrary blob of data for use in the free
// list:
// * Set the size to n, but:
//  * Remove one unit from size for the header.
//  * Round down to the nearest unit, discarding the
//    remainder.
// * Initialize header's next pointer to itself.
header* initialize_new_chunk(void* const p, const size_t size) {
  header* new_chunk = (header*)p;
  size_t usable_bytes = size - unit_size - (size % unit_size);
  new_chunk->size = usable_bytes / unit_size;
  new_chunk->next = new_chunk;
  return new_chunk;
}
