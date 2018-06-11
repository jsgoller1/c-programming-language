fopen_j
---
`fopen()` (and related functions) as written by Joshua.

## Directions
**Exercise 8-2**. Rewrite `fopen()` and `_fillbuf()` with fields instead of explicit bit 
operations. Compare code size and execution speed.

**Exercise 8-3**. Design and write _flushbuf, fflush, and fclose.

**Exercise 8-4**. The standard library function `int fseek(FILE *fp, long offset, int origin)` is identical to lseek except that fp is a file pointer instead of a file descriptor and the return value is an int status, not a position. Write `fseek()`. Make sure that your `fseek()` coordinates properly with the buffering done for the other functions of the library. 
