#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "common.h"
#include "malloc_j.h"

Header base = {{0, 0, 0}};  // empty list to get started
Header* freep = NULL;       // start of free list

void* init_base = NULL;  // base of allocated initial page used
void* init_end = NULL;   // last address in the init_page
void* init_ptr = NULL;   // current offset in init_page

// init(): create initial large block of memory
// to avoid repeated calls to resize list.
void init(void) {
  size_t size = (INIT_PAGE_SIZE < MIN_ALLOC) ? MIN_ALLOC : INIT_PAGE_SIZE;

  if ((init_base = mmap(NULL, size, PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED) {
    char* err_desc = strerror(errno);
    printf("Couldn't allocate initial page: %s.\n", err_desc);
  }
  init_ptr = init_base;
  init_end = (char*)init_base +
             INIT_PAGE_SIZE;  // this relies on the assumption that the address
                              // range of the page returned by mmap() starts at
                              // a lower address and ends at a higher one
  /*
  printf(
      "init() | init_page initialized:\n"
      "* init_base: %p\n"
      "* init_ptr: %p\n"
      "* init_end: %p\n"
      "* size (B): %lu\n",
      init_base, init_ptr, init_end, size);
  */
}

void cleanup(void) {
  if (munmap(init_base, INIT_PAGE_SIZE) == -1) {
    char* err_desc = strerror(errno);
    printf("Couldn't unmap initial page: %s.\n", err_desc);
    return;
  }
  init_base = NULL;
  init_end = NULL;
  init_ptr = NULL;
  freep = NULL;
  // printf("cleanup() | Unmapped initial page.\n");
}
