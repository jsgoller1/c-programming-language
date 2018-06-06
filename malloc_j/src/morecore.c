#include <unistd.h>
#include "malloc_j.h"

static unsigned int block_count = 0;

// jbrk(): similar to sbrk()/brk(), but modifies
// init_page instead of the program break. Only morecore()
// should call jbrk(), hence static.
static void* jbrk(unsigned int nu) {
  char* start = (char*)init_ptr;
  char* end = (char*)init_ptr + nu;
  // printf("jbrk() | Current init_ptr: %p\n", init_ptr);
  // printf("jbrk() | End of init page: %p\n", init_end);
  // printf("jbrk() | End of requested block: %p\n", (void*)end);
  // printf("jbrk() | Requested block too big? %d\n", (end > (char*)init_end));

  if (end <= (char*)init_end) {
    // printf("jbrk() | Obtaining more of init_page.\n");
    init_ptr = (void*)end;
    return (void*)start;
  } else {
    // printf("jbrk() | Can't get anymore of the page.\n");
    return NULL;
  };
}

// morecore(): obtain more memory for malloc_j
Header* morecore(unsigned int nu) {
  void* cp;
  Header* up;

  if (nu < MIN_ALLOC) {
    nu = MIN_ALLOC;
  }

  printf("morecore() | Attempting to obtain %lu bytes of the init_page.\n",
         nu * sizeof(Header));

  cp = jbrk(nu * sizeof(Header));
  if (cp == (void*)-1) {  // no space
    return NULL;
  }
  up = (Header*)cp;
  up->s.size = nu;
  up->s.data = up + 1;
  up->s.block_id = ++block_count;
  free_j((void*)up);
  return freep;
}
