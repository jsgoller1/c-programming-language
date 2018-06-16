#include <stdio.h>
#include <unistd.h>

#include "fopen_j.h"

// getc(): retrieve a single character from the file
int getc_j(FILE_J* fp) {
  int ret;
  // determine if the read would be outside of the buffer;
  // if so, flush the buffer, fill with the next region
  // of data, and reset the ptr before the read.
  if (fp->ptr == fp->buff + BUFF_SIZE) {
    printf("getc_j() | flushing the buffer and getting new data...\n");
    _flush_buff(fp);
    _fill_buff(fp);
    lseek(fp->fd, -BUFF_SIZE, SEEK_CUR);
    fp->ptr = fp->buff;
  }

  ret = (int)*(fp->ptr);
  fp->ptr++;
  return ret;
}

// putc(): write a single char to a FILE_J
int putc_j(FILE_J* fp, int character) {
  // same flushing behavior as getc_j()
  if (fp->ptr == fp->buff + BUFF_SIZE) {
    printf("putc_j() | recycling buffer...\n");
    _flush_buff(fp);
    _fill_buff(fp);
    lseek(fp->fd, -BUFF_SIZE, SEEK_CUR);
    fp->ptr = fp->buff;
  }
  *(fp->ptr) = (char)character;
  fp->ptr++;
  fp->dirty = 1;
  return 0;
}
