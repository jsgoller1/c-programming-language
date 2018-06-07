#include <stdio.h>
#include <unistd.h>
#include "common.h"

// Misc
#define MiB (1 << 20)

typedef struct header {  // block header
  size_t size;           // size of block (4 bytes)
  union header* ptr;     // next block if on free list (8 bytes)
} header;

// init.c
#define INIT_PAGE_SIZE (500 * MiB)  // size of init_page;

// extern header base;        // empty list to get started
extern header* free_list;  // start of free list
// extern void* init_base;  // base of allocated initial page used
// extern void* init_end;   // last address in the init_page
// extern void* init_ptr;   // current offset in init_page

void init(void);
void cleanup(void);

// malloc_j.c
#define MIN_ALLOC 1024  // always get at least 1024 bytes

void* malloc_j(size_t nbytes);

// free_j.c
void free_j(void* ap);
void bfree(void* p, int n);

// calloc_j.c
void* calloc_j(const size_t size, const size_t count);

// stats.c
extern size_t total_mem;
extern size_t free_mem;
extern size_t allocated_mem;
extern size_t bfree_mem;

extern size_t total_chunks;
extern size_t free_chunks;
extern size_t allocated_chunks;
extern size_t bfree_chunks;

extern size_t void* display_metrics(void);
extern size_t void* display_mem(void);
extern size_t void* display_chunks(void);
