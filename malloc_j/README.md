malloc_j
---
`malloc()` as implemented by Joshua.

## Notes
Because the original K&R implementation uses `sbrk()` (which is considered obsolete), I have opted for a slightly different but common approach using `mmap()` instead, wherein I allocate a single large page at the beginning of program execution and pull from that via a custom `jbrk()` instead.

## Directions
**Exercise 8-6**. The standard library function calloc(n,size) returns a pointer to n objects of size size, with the storage initialized to zero. Write calloc, by calling malloc or by modifying it.

**Exercise 8-7**. malloc accepts a size request without checking its plausibility; free believes that the block it is asked to free contains a valid size field. Improve these routines so they take more pains with error checking.

**Exercise 8-8**. Write a routine bfree(p,n) that will free an arbitrary block p of n characters into the free list maintained by malloc and free. By using b free, a user can add a static or external array to the free list at any time.

## Special thanks 
* [Elliott Jin (@robot-dreams)](https://github.com/robot-dreams) for some guidance on `sbrk()` use and strategy feedback.
