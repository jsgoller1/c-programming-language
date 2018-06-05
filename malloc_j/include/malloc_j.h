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

static Header base = {{0, 0}};  // empty list to get started
static Header* freep = NULL;    // start of free list

#define MiB (1 << 20)
#define INIT_PAGE_SIZE (500 * MiB)  // size of init_page;
static void* init_base = NULL;      // base of allocated initial page used
static void* init_end = NULL;       // last address in the init_page
static void* init_ptr = NULL;       // current offset in init_page

void* malloc_j(unsigned int nbytes);
void free_j(void* ap);
Header* morecore(unsigned int nu);
void init(void);
