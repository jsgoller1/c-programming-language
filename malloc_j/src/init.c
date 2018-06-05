#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "common.h"
#include "malloc_j.h"

// init(): create initial large block of memory
// to avoid repeated calls to resize list.
void init(void) {
  if ((init_base = mmap(NULL, INIT_PAGE_SIZE, PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED) {
    char* err_desc = strerror(errno);
    printf("Couldn't allocate initial page: %s.\n", err_desc);
  }
  init_ptr = init_base;
  init_end = (char*)init_base +
             INIT_PAGE_SIZE;  // this relies on the assumption that the address
                              // range of the page returned by mmap() starts at
                              // a lower address and ends at a higher one
  printf("init_page initialized: %p\n", init_base);
}
