#include <stdio.h>
#include <unistd.h>
#include "common.h"

// Misc
#define MiB (1 << 20)

typedef struct header {
  unsigned int size;    // size of block
  struct header* next;  // next block if on free list
  void* data;           // the actual block of data
} header;

// init.c
#define MAX_MEM (500 * MiB)  // size of init_page;

// extern header base;
extern header* freep;
extern void* header_page;
extern void* init_page;

void init(void);
void cleanup(void);

// morecore.c
#define MIN_ALLOC 1024  // always get at least 1024 bytes

Header* morecore(unsigned int nu);

// malloc_j.c
void* malloc_j(unsigned int nbytes);

// free_j.c
void free_j(void* ap);
void bfree(void* p, int n);

// calloc_j.c
void* calloc_j(const unsigned int size, const unsigned int count);
