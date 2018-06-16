#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "fopen_j.h"

static void handle_buffer(FILE_J* fp) {
  _flush_buff(fp);
  if (_fill_buff(fp) == EOF) {
    // we are at the end of the file, so
    // there is nothing else to keep track of.
    // Unset the data in the buffer
    printf("handle_buffer() | fill_buff got EOF, memsetting.\n");
    memset(fp->buff, '\0', BUFF_SIZE);
  } else {
    // we are not at the end of the file,
    // so the next write should overwrite data
    // that was filled in the buffer. Seek back.
    printf("handle_buffer() | fill_buff got 0, seeking.\n");
    lseek(fp->fd, -BUFF_SIZE, SEEK_CUR);
  }
  fp->ptr = fp->buff;
}

// getc(): retrieve a single character from the file
int getc_j(FILE_J* fp) {
  int ret;
  // determine if the read would be outside of the buffer;
  // if so, flush the buffer, fill with the next region
  // of data, and reset the ptr before the read.
  if (fp->ptr == fp->buff + BUFF_SIZE) {
    printf("getc_j() | handling buffer.\n");
    handle_buffer(fp);
  }

  ret = (int)*(fp->ptr);
  fp->ptr++;
  return ret;
}

// putc(): write a single char to a FILE_J
int putc_j(FILE_J* fp, int character) {
  // same flushing behavior as getc_j()
  if (fp->ptr == fp->buff + BUFF_SIZE) {
    printf("putc_j() | handling buffer.\n");
    handle_buffer(fp);
  }

  *(fp->ptr) = (char)character;
  fp->ptr++;
  fp->dirty = 1;
  return 0;
}
