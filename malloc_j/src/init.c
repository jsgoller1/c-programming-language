#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "common.h"
#include "malloc_j.h"

// header base = {0, 0};      // empty list to get started
header* free_list = NULL;  // start of free list

// void* init_base = NULL;  // base of allocated initial page used
// void* init_end = NULL;   // last address in the init_page
// void* init_ptr = NULL;   // current offset in init_page

// init(): create first item in the free list by getting a massive page from
// mmap()
void init(void) {
  size_t size = (INIT_PAGE_SIZE < MIN_ALLOC) ? MIN_ALLOC : INIT_PAGE_SIZE;
  void* init_page;

  if ((init_page = mmap(NULL, size, PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED) {
    char* err_desc = strerror(errno);
    printf("Couldn't allocate initial page: %s.\n", err_desc);
  }

  free_j(init_page + sizeof(header));

  printf("init() | init_page initialized:\n");
  display_metrics();
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
