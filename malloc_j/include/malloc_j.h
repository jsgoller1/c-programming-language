#include <stdio.h>
#include <unistd.h>
#include "common.h"

// Misc
#define MiB (1 << 20)

typedef struct header {  // block header
  size_t size;           // size of block (4 bytes)
  struct header* next;   // next block if on free list (8 bytes)
} header;

static const size_t unit_size = sizeof(header);

// init.c
extern header* free_list;  // start of free list
extern void* init_page;    // base of allocated initial page used
extern size_t total_units;

int init(const size_t desired_page_size);
int cleanup(void);
header* initialize_new_chunk(void* const p, const size_t size);

// malloc_j.c
void* malloc_j(const size_t nbytes);
void* calloc_j(const size_t size, const size_t count);

// free_j.c
int free_j(void* const chunk);
int bfree(void* const p, const size_t n);
