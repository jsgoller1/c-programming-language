#include <stdio.h>

#include "fopen_j.h"

// getc(): retrieve a single character from the file
int getc_j(FILE_J* fp) {
  int ret;

  // determine if the read would be outside of the buffer;
  // if so, flush the buffer.
  if (fp->ptr == fp->buff + BUFF_SIZE) {
    printf("getc_j() | recycling buffer...\n");
    if (recycle_buffer(fp) == -1) {
      return EOF;
    }
  }

  ret = (int)*(fp->ptr);
  fp->ptr++;

  return ret;
}

// putc(): write a single char to a FILE_J
int putc_j(FILE_J* fp, int character) {
  // determine if the write would be outside of the buffer;
  // if so, flush the buffer.
  if (fp->ptr == fp->buff + BUFF_SIZE) {
    printf("putc_j() | recycling buffer...\n");
    if (recycle_buffer(fp) == -1) {
      return EOF;
    }
  }
  *(fp->ptr) = (char)character;
  fp->ptr++;
  fp->dirty = 1;
  return 0;
}
