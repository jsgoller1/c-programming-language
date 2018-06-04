#include <stdio.h>

#ifdef DEBUG
#define DPRINT(msg) printf("%s", msg);
#else
#define DPRINT(msg) printf("");
#endif

typedef unsigned Align;  // align blocks to long boundary

union header {  // block header
  struct {
    Align x;            // force alignment of blocks
    unsigned size;      // size of that block
    union header* ptr;  // next block if on free list
  } s;
};

typedef union header Header;

static Header base;           // empty list to get started
static Header* freep = NULL;  // start of free list

void* malloc_j(unsigned nbytes);
void free_j(void* ap);
Header* morecore(unsigned nu);
