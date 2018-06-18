#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "fopen_j.h"

// getc(): retrieve a single character from the file
int getc_j(FILE_J* fp) {
  int ret;
  // if read would go outside of the buffer, flush it,
  // and fill with the next region
  if (fp->ptr == fp->buff + BUFF_SIZE) {
    _flushbuff(fp);
    _fillbuff(fp);
    fp->ptr = fp->buff;
  }

  // Increment fp after read, then return
  ret = (int)*(fp->ptr);
  fp->ptr++;
  return ret;
}

// putc(): write a single char to a FILE_J
int putc_j(FILE_J* fp, int character) {
  // same flushing behavior as getc_j()
  if (fp->ptr == fp->buff + BUFF_SIZE) {
    _flushbuff(fp);
    _fillbuff(fp);
    fp->ptr = fp->buff;
  }

  // Increment fp after write, then return
  *(fp->ptr) = (char)character;
  fp->ptr++;
  return 0;
}
