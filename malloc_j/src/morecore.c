#include "malloc_j.h"
#include "unistd.h"

#define NALLOC 1024

// morecore(): ask OS for more memory
static Header* morecore(unsigned nu) {
  char* cp;
  Header* up;

  cp = sbrk(nu * sizeof(Header));
  if (cp == (char*)-1) {  // no space
    return NULL;
  }
  up = (Header*)cp;
  up->s.size = nu;
  free_j((void*)(up + 1));
  return freep;
}
