#include <stdio.h>
#include <unistd.h>

#include "fopen_j.h"

// fseek(): flush the buffer contents, seek to the correct place,
// refill the buffer, and correct the file position after the read.
int fseek_j(FILE_J *const fp, const long offset, const int whence) {
  off_t pos;

  _flushbuff(fp);
  pos = lseek(fp->fd, offset, whence);
  _fillbuff(fp);

  fp->ptr = fp->buff;
  return 0;
}
