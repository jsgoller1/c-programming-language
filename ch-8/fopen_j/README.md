fopen_j
---
`fopen()` (and related functions) as written by Joshua.

## Design
`FILE_J` mimics a `FILE` enough to pass the exercises listed below. A `FILE_J` consists of:
- a file descriptor
- a buffer for buffered I/O
- metadata
  - a pointer to an address within the buffer.
  - a dirty bit
- flags

The buffer acts as a "shadow" of the file descriptor. Reads, writes, and seeks occur to it until one would cause the pointer to move outside the buffer. When
this happens, if the dirty bit on the buffer is set, it is flushed back to the file.
Then, the buffer is refilled with data from the file, and the `FILE_J` pointer is reset to the first address of the buffer. The `FILE_J` manages the file descriptor's pointer and will seek as necessary.

## Directions
**Exercise 8-2**. Rewrite `fopen()` and `_fillbuf()` with fields instead of explicit bit
operations. Compare code size and execution speed.

**Exercise 8-3**. Design and write _flushbuf, fflush, and fclose.

**Exercise 8-4**. The standard library function `int fseek(FILE *fp, long offset, int origin)` is identical to lseek except that fp is a file pointer instead of a file descriptor and the return value is an int status, not a position. Write `fseek()`. Make sure that your `fseek()` coordinates properly with the buffering done for the other functions of the library.

## Notes
* The modern signature for `fseek()` is:```
fseek(FILE *stream, long offset, int whence);
```
