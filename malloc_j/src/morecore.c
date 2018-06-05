#include <unistd.h>
#include "malloc_j.h"

#define NALLOC 1024

// jbrk(): similar to sbrk()/brk(), but modifies
// init_page instead of the program break. Only morecore()
// should call jbrk(), hence static.
static void* jbrk(unsigned int nu) {
  printf("Current init_ptr: %p\n", init_ptr);
  char* start = (char*)init_ptr;
  char* end = (char*)init_ptr + nu;
  printf("End of init page: %p\n", init_end);
  printf("End of requested block: %p\n", (void*)end);

  if (end <= (char*)init_end) {
    init_ptr = (void*)end;
    return (void*)start;
  } else {
    return NULL;
  };
}

// morecore(): obtain more memory for malloc_j
Header* morecore(unsigned int nu) {
  void* cp;
  Header* up;

  if (nu < NALLOC) {
    nu = NALLOC;
  }

  cp = jbrk(nu * sizeof(Header));
  if (cp == (void*)-1) {  // no space
    return NULL;
  }
  up = (Header*)cp;
  up->s.size = nu;
  free_j((void*)(up + 1));
  return freep;
}
