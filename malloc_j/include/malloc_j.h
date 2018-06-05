#include <stdio.h>
#include <unistd.h>
#include "common.h"

// Misc
#define MiB (1 << 20)

union header {  // block header
  struct {
    unsigned int
        block_id;  // useful value for debugging; not required for program (4
                   // bytes)
    unsigned int size;  // size of block (4 bytes)
    union header* ptr;  // next block if on free list (8 bytes)
  } s;
};

typedef union header Header;

// init.c
#define INIT_PAGE_SIZE (500 * MiB)  // size of init_page;

extern Header base;      // empty list to get started
extern Header* freep;    // start of free list
extern void* init_base;  // base of allocated initial page used
extern void* init_end;   // last address in the init_page
extern void* init_ptr;   // current offset in init_page

void init(void);
void cleanup(void);

// morecore.c
#define MIN_ALLOC 1024  // always get at least 1024 bytes

Header* morecore(unsigned int nu);

// malloc_j.c
void* malloc_j(unsigned int nbytes);

// free_j.c
void free_j(void* ap);

// calloc_j.c
void* calloc_j(unsigned int units, unsigned int count);
