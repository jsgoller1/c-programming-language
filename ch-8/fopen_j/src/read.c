#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "fopen_j.h"

int getc(FILE_J *p) {
  if (p->count >= 1) {
    _buffered_read(p);
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
  int bufsize;

  // quit if flags indicate reading isn't possible.
  if (fp->flags._READ & !(fp->flags._EOF | fp->flags._ERR)) {
    return EOF;
  }

  // set up buffer if necessary
  bufsize = (fp->flags._UNBUF) ? 1 : BUFSIZ;
  if (fp->base == NULL_J) {  // no buffer yet
    if ((fp->base = (char *)malloc((unsigned long)bufsize)) == NULL) {
      return EOF;
    }
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
