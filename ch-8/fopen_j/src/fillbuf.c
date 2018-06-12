#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "fopen_j.h"

// _fillbuf: allocate and fill input buffer
int _fillbuf(FILE_J *fp) {
  int bufsize;

  // quit if flags indicate reading isn't possible.
  if (fp->flags._READ & !(fp->flags._EOF | fp->flags._ERR)) {
    return EOF;
  }

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
