#include <stdio.h>
#include <unistd.h>

#include "fopen_j.h"

// fseek(): flush the buffer contents, seek to the correct place,
// refill the buffer, and correct the file position after the read.
int fseek_j(FILE_J *const fp, const long offset, const int whence) {
  if (_flushbuff(fp) == -1) {
    fp->flags._ERR = true;
    return -1;
  }
  if (lseek(fp->fd, offset, whence) == -1) {
    fp->flags._ERR = true;
    return -1;
  }

  if (_fillbuff(fp) == -1) {
    fp->flags._ERR = true;
    return -1;
  }

  fp->ptr = fp->buff;
  return 0;
}
