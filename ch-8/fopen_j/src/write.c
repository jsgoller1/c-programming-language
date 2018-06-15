#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#include "fopen_j.h"

// putc(): write to file; check if the IO buffer needs flushing,
// then write to it.
int putc_j(int character, FILE_J* fp) {
  if (fp->count <= 0) {
    printf("putc_j() | flushing buffer...\n");
    if (_flush_buf(fp) == -1) {
      return -1;
    }
  }
  *(fp->ptr) = (char)character;
  fp->ptr++;
  fp->count--;
  return 0;
}

/*
_flush_buf: Implements buffered writing. This function is called
when attempting to write to a FILE_J - the buffer is filled (or created) and
putc() puts characters into it until it is large enough to be flushed to the
actual file descriptor. This prevents unnecessary write() syscalls.
*/
int _flush_buf(FILE_J* fp) {
  // quit if flags indicate writing isn't possible.
  if (!fp->flags._WRITE) {
    printf("_flush_buf() | write flag not set.\n");
    return EOF;
  }
  if (fp->flags._EOF | fp->flags._ERR) {
    printf("_flush_buf() | cannot write to file.\n");
    return EOF;
  }

  // set the buffer pointer to original position;
  // back out if we fail, but reset buffer if we succeed.
  size_t writesize = (size_t)(BUFSIZ_J - fp->count);
  write(fp->fd, fp->base, writesize);
  if (errno) {
    perror("_flush_buf(): Couldn't flush buffer - ");
    fp->flags._ERR = true;
    return -1;
  } else {
    fp->ptr = fp->base;
    fp->count = BUFSIZ_J;
  }
  printf("_flush_buf() | buffer is flushed.\n");
  return 0;
}
