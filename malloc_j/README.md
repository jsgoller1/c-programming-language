malloc_j
---
`malloc()` as written by Joshua.

## Implementation
I stuck with K&R's approach in the following ways:
* `malloc_j()`, `calloc_j()`, and `free_j()` are used the same way `malloc()`, `calloc()`, and `free()` are used. `calloc_j()` calls `malloc_j()` with the product of its arguments.
* `malloc_j()` and `calloc_j()` both obtain at least 1024 byes to maintain block alignment. 
* The free list is ordered by the addresses of the pointers.
* `free()_j` merges free chunks that are contiguous via `merge_chunks()`.

I deviated from K&R in a few key ways:
* `sbrk()` is considered obsolete. Required memory is mapped via `mmap()` in `init()`, which initialized the free list with a single massive chunk. Successive calls to `malloc_j()` / `calloc_j()` will split this chunk.
* Given the above, `morecore()` was unnecessary and is removed.
* `Header` has been modified in two important ways:
  * `bfree()` (see 8-8 below) presents an interesting edge case where we cannot safely assume that the bytes preceeding a block given to `free_j()` contain a header. Because of this, headers have a `void* data` pointer to the chunk they represent. When `bfree()` is asked to add a new chunk of memory to the free list, it will attempt to split the largest chunk to make a new header (and then create another header for the remainder of the memory in the chunk).
  * When headers are created due to chunk splits in `malloc_j()`, they are guaranteed to be contiguous with the memory they represent, but not if they are created by `bfree()`. Because of this, it will be possible to determine in `free_j()`' if chunks with headers can be combined with existing free chunks, but this will never occur for chunks placed in the list by `bfree()`.

## Directions
**Exercise 8-6**. The standard library function calloc(n,size) returns a pointer to n objects of size size, with the storage initialized to zero. Write calloc, by calling malloc or by modifying it.

**Exercise 8-7**. malloc accepts a size request without checking its plausibility; free believes that the block it is asked to free contains a valid size field. Improve these routines so they take more pains with error checking.

**Exercise 8-8**. Write a routine bfree(p,n) that will free an arbitrary block p of n characters into the free list maintained by malloc and free. By using b free, a user can add a static or external array to the free list at any time.

## Special thanks 
* [Elliott Jin (@robot-dreams)](https://github.com/robot-dreams) for some guidance on `sbrk()` use.
