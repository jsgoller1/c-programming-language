#include <stdio.h>
#include <unistd.h>
#include "common.h"

union header {  // block header
  struct {
    unsigned long size;  // size of that long (8 bytes)
    union header* ptr;   // next block if on free list (8 bytes)
  } s;
};

typedef union header Header;

extern Header base;    // empty list to get started
extern Header* freep;  // start of free list

#define MiB (1 << 20)
#define INIT_PAGE_SIZE (500 * MiB)  // size of init_page;
extern void* init_base;             // base of allocated initial page used
extern void* init_end;              // last address in the init_page
extern void* init_ptr;              // current offset in init_page

void* malloc_j(unsigned int nbytes);
void free_j(void* ap);
Header* morecore(unsigned int nu);
void init(void);
void cleanup(void);
