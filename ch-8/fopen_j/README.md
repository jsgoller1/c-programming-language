fopen_j
---
`fopen()` (and related functions) as written by Joshua. This was much trickier than anticipated and required a couple of re-writes
before I was able to catch all edge cases. Any function or struct whose name would collide with the standard library has `_j` appended to it.

## Design notes
### FILE_J structure
- a `FILE_J` is my version of `FILE`; it contains
  - `int fd` - the underlying file descriptor
  - `char* buff` - a pointer to the buffered data
    - `buff` is always `BUFF_SIZE` size
  - `char* ptr` - a pointer to the current position in `buff`
  - `FLAGS flags` - a struct containing flag data about the file
    - read, write, EOF, error
### Notes
- a `FILE_J` is initialized with whatever data is at file position 0.
- reads and writes occur to buffer; syscalls are only made when the buffer is flushed or seeking occurs
- when buffer is full, it is written to the file.
- seeking moves to the desired position in the file; seeks require flushing.
- the client needs no knowledge of whether buffering is occuring or not.
- there should never be contents in the file that are not in the buffer, unless previous calls to `write()` occurred and a call to `_flushbuff()` will correctly overwrite those parts of the file.

### Client functions
- Each client function should behave as they would on a normal `FILE`.
  - `fgetc_j()`
    - reads a character from the buffer
    - triggers a `_flushbuff()` if buffer is exhausted
    - returns
      - next char in file on success.
      - EOF on error or actual EOF
  - `fputc_j()`
    - writes a character to the buffer
    - triggers a `_flushbuff()` if buffer is exhausted
    - returns
      - character written on success
      - EOF on error
  - `fseek_j()`
    - moves the file position either (absolutely or relative to current)
    - returns 0 on success, and -1 on error
  - `fflush_j()`
    - writes all buffered data to file
    - 0 on success, EOF on error

### Private functions
- `_fillbuff()`
  - Fills the I/O buffer with data from the file, via `read()`
  - Returns 0 on success, -1 on failure
  - Because `_fillbuff()` calls `read()`, it handles seeking the
    file descriptor back to the original position so that subsequent
    `_flushbuff()` calls write to the correct place.
- `_flushbuff()`
  - Writes to the file however many bytes exist between `FILE_J->buff` and `FILE_J->ptr`.
  - Returns 0 on success, -1 on failure

### Edge cases and expected behavior
  - case: `_fillbuff()` occurs on an empty file
    - expected: the read returns EOF
  - case: writes occur and `fflush()` is called, but the buffer isn't full
    - expected: only written characters are flushed to the file
    - Example:
      - file: `[]`
      - buffer: `[A, B, C, \0, \0]` (buffer is not full)
      - `flush()` is called
      - file: `[A, B, C]`
  - case: reads and writes are intermixed
    - expected: the correct characters are read/written in the expected order
      - `fgetc_j()` should increment `FILE_J->count`
    - Example:
      - file: `[A, B, C, D, E, F, G, ... , Z]`
      - buffer: `[A, B, C, D, E]`
      - `putc(1)` is called twice, `getc()` twice, then `putc(2) twice`. Result:
      - file: `[1, 1, C, D, 2, F, G, ... , Z]`
      - buffer: `[2, G, H, I, J]`


## Directions
**Exercise 8-2**. Rewrite `fopen()` and `_fillbuf()` with fields instead of explicit bit
operations. Compare code size and execution speed.

**Exercise 8-3**. Design and write _flushbuf, fflush, and fclose.

**Exercise 8-4**. The standard library function `int fseek(FILE *fp, long offset, int origin)` is identical to lseek except that fp is a file pointer instead of a file descriptor and the return value is an int status, not a position. Write `fseek()`. Make sure that your `fseek()` coordinates properly with the buffering done for the other functions of the library.
