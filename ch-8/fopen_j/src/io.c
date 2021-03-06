#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "fopen_j.h"

// getc(): retrieve a single character from the file
int getc_j(FILE_J* const fp) {
  int ret;
  // if read would go outside of the buffer, flush it,
  // and fill with the next region
  if (fp->ptr == fp->buff + BUFF_SIZE) {
    if (fflush_j(fp) == -1) {
      fp->flags._ERR = true;
      return EOF;
    }
    fp->ptr = fp->buff;
  }

  // Increment fp after read, then return
  ret = (int)*(fp->ptr);
  fp->ptr++;
  return ret;
}

// putc(): write a single char to a FILE_J
int putc_j(FILE_J* const fp, const int character) {
  // same flushing behavior as getc_j()
  if (fp->ptr == fp->buff + BUFF_SIZE) {
    if (fflush_j(fp) == -1) {
      fp->flags._ERR = true;
      return EOF;
    }
    fp->ptr = fp->buff;
  }

  // Increment fp after write, then return
  *(fp->ptr) = (char)character;
  fp->ptr++;
  return 0;
}
