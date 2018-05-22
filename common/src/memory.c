/*
 * --------------------------------------------------------
 *  Memory / storage
 * --------------------------------------------------------
 */

#define ALLOCSIZE 100  // Amount of available space

static char allocbuf[ALLOCSIZE];  // storage for alloc
static char *allocp = allocbuf;   // next free position

char *myalloc(int n)  // return pointer to n characters
{
  // if the requested n bytes is less than or equal the amount of
  // remaining free space (base addr + total size - currently used size)
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    // printf("alloc(): allocating %d bytes.\n", n);
    return allocp - n;  // old p
  } else {
    printf("alloc(): can't allocate %d bytes.\n", n);
    return 0;
  }
}

void myafree(char *p) {  // free storage pointed to by p
  // if the pointer is within the allocbuff:
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
    allocp = p;  // doing this means if you de-allocate a lower address when
                 // higher ones are allocated, you lose everything above it.
  }
}
