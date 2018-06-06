#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "common.h"
#include "malloc_j.h"

// see malloc_j.h for comments
// header base = {0, 0, 0};
header* free_list = NULL;
void* init_page = NULL;

// init(): Get initial memory from OS, and set up free list
void init(void) {
  size_t init_page_size = (MAX_MEM < MIN_ALLOC) ? MIN_ALLOC : MAX_MEM;
  init_page = mmap(NULL, init_page_size, PROT_READ | PROT_WRITE,
                   MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  if (init_page == MAP_FAILED) {
    char* err_desc = strerror(errno);
    printf("Couldn't allocate init page: %s.\n", err_desc);
  }

  printf(
      "init() | init_page initialized:\n"
      "* init_base: %p\n"
      "* init_ptr: %p\n"
      "* init_end: %p\n"
      "* size (B): %lu\n",
      init_base, init_ptr, init_end, size);
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
