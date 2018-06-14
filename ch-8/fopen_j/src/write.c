#include <errno.h>
#include <stdio.h>

#include "fopen_j.h"

// putc(): write to file; check if the IO buffer needs flushing,
// then write to it.
int putc_j(int character, FILE_J* file) {
  if (p->count <= 0) {
    printf("putc_j() | flushing buffer...");
    if (_flush_buf(character, stream) == -1) {
      return -1;
    }
  }
  p->ptr = character;
  p->ptr++;
  p->count--;
}

/*
_flush_buf: Implements buffered writing. This function is called
when attempting to write to a FILE_J - the buffer is filled (or created) and
putc() puts characters into it until it is large enough to be flushed to the
actual file descriptor. This prevents unnecessary write() syscalls.
*/
int _flush_buf(FILE_J* fp) {
  // quit if flags indicate writing isn't possible.
  if (fp->flags._READ & !(fp->flags._EOF | fp->flags._ERR)) {
    return EOF;
  }

  // set the buffer pointer to original position;
  // back out if we fail, but reset buffer if we succeed.
  write(fp->fd, fp->base, BUFSIZ);
  if (errno) {
    perror("_flush_buf(): Couldn't flush buffer - ");
    fp->flags._ERR = true;
    return -1;
  } else {
    fp->ptr = fp->base;
    fp->count = BUFSIZ;
  }

  return 0;
}
