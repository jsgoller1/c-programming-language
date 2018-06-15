#include <stdio.h>

#include "fopen_j.h"

// getc(): retrieve a single character from the file
int getc_j(FILE_J* fp) {
  int ret;

  // determine if the read would be outside of the buffer;
  // if so, flush the buffer.
  if (fp->ptr == fp->buff + BUF_SIZE) {
    printf("getc_j() | recycling buffer...\n");
    if (recycle_buffer(fp) == -1) {
      return EOF;
    }
  }

  ret = (int)*(fp->ptr);
  fp->ptr++;
  fp->count--;

  return ret;
}

// putc(): write a single char to a FILE_J
int putc_j(int character, FILE_J* fp) {
  // determine if the write would be outside of the buffer;
  // if so, flush the buffer.
  if (fp->ptr == fp->buff + BUF_SIZE) {
    printf("putc_j() | recycling buffer...\n");
    if (recycle_buffer(fp) == -1) {
      return EOF;
    }
  }
  *(fp->ptr) = (char)character;
  fp->ptr++;
  return 0;
}
