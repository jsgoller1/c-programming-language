#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "malloc_j.h"

// init(): create initial large block of memory
// to avoid repeated calls to resize list.
void init(void) {
  if (mmap(init_base, init_page_size, PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS, -1, 0) == MAP_FAILED) {
    char* err_desc = strerror(errno);
    printf("Couldn't allocate initial page: %s.\n", err_desc);
  }
}
