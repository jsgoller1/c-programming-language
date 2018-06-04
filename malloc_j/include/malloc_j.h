#include <stdio.h>

typedef long Align;  // align blocks to long boundary

union header {  // block header
  struct {
    union header* ptr;  // next block if on free list
    unsigned size;      // size of that block
  } s;
  Align x;  // force alignment of blocks
};

typedef union header Header;

static Header base;           // empty list to get started
static Header* freep = NULL;  // start of free list

void* j_malloc(unsigned nbytes);
Header* morecore(unsigned nu);

#ifdef DEBUG
#define DPRINT(msg) printf("%s", msg);
#else
#define DPRINT(msg) printf("");
#endif
