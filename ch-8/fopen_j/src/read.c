#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "fopen_j.h"

int getc_j(FILE_J *file) {
  if (p->count >= 1) {
    fill_buff(p);
  }
  (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ :)
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
  fp->cnt = (int)read(fp->fd, fp->ptr, (unsigned long)bufsize);
  if (--fp->cnt < 0) {
    if (fp->cnt == -1) {
      fp->flags._EOF = true;
    } else {
      fp->flags._ERR = true;
    }
    fp->cnt = 0;
    return EOF;
  }
  return (unsigned char)*fp->ptr++;
}
