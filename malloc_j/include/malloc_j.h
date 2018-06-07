#include <stdio.h>
#include <unistd.h>
#include "common.h"

// Misc
#define MiB (1 << 20)

typedef struct header {  // block header
  size_t size;           // size of block (4 bytes)
  struct header* next;   // next block if on free list (8 bytes)
} header;

// init.c
#define INIT_PAGE_SIZE (500 * MiB)  // size of init_page;

extern header* free_list;  // start of free list
extern void* init_page;    // base of allocated initial page used

int init(void);
int cleanup(void);

// malloc_j.c
void* malloc_j(size_t nbytes);
void* calloc_j(const size_t size, const size_t count);

// free_j.c
int free_j(void* ap);
int bfree(void* p, size_t n);

// stats.c
extern size_t total_mem;
extern size_t free_mem;
extern size_t allocated_mem;
extern size_t bfree_mem;

extern size_t total_chunks;
extern size_t free_chunks;
extern size_t allocated_chunks;
extern size_t bfree_chunks;

void* display_metrics(void);
void* display_mem(void);
void* display_chunks(void);
