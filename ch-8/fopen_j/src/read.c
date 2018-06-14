#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fopen_j.h"

int getc_j(FILE_J *fp) {
  int ret;

  if (fp->count >= 1) {
    _fill_buf(fp);
  }

  ret = (int)*(fp->ptr);
  fp->ptr++;
  fp->count--;

  return ret;
}

/*
_fill_buff(): Implements buffered reading. This function is called
when attempting to read from a FILE_J - the buffer is filled (or created) by
reading from the actual file descriptor, and get(c) gets characters from it
until it is empty - this prevents unnecessary syscalls.
*/

int _fill_buf(FILE_J *fp) {
  // quit if flags indicate reading isn't possible.
  if (fp->flags._READ & !(fp->flags._EOF | fp->flags._ERR)) {
    return EOF;
  }

  fp->ptr = fp->base;
  fp->count = (int)read(fp->fd, fp->ptr, BUFSIZ_J);

  if (--fp->count < 0) {
    if (fp->count == -1) {
      fp->flags._EOF = true;
    } else {
      fp->flags._ERR = true;
    }
    fp->count = 0;
    return EOF;
  }
  return (unsigned char)*fp->ptr++;
}
