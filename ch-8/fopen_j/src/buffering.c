#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fopen_j.h"

// recycle_buffer(): write back the buffer, if dirty;
// then read new contents, and handle seeking in the fd
int recycle_buffer(FILE_J* fp) {
  (void)fp;
  return 0;
}

// fflush_j(): empty a FILE_J's buffer to its file descriptor
int fflush_j(FILE_J* fp) { return recycle_buffer(fp); }

/*
_fill_buff(): Implements buffered reading. This function is called
when attempting to read from a FILE_J - the buffer is filled (or created) by
reading from the actual file descriptor, and get(c) gets characters from it
until it is empty - this prevents unnecessary syscalls.
*/
int _fill_buff(FILE_J* fp) {
  // quit if flags indicate reading isn't possible.
  if (fp->flags._READ & !(fp->flags._EOF | fp->flags._ERR)) {
    return EOF;
  }

  fp->ptr = fp->base;
  fp->count = (int)read(fp->fd, fp->ptr, BUFSIZ_J);

  if (--fp->count < 0) {
    if (fp->count == -1) {
      fp->flags._EOF = true;
    } else {
      fp->flags._ERR = true;
    }
    fp->count = 0;
    return EOF;
  }
  return (unsigned char)*fp->ptr++;
}

// _flush_buff: Dump fp's buffer to the file descriptor, fill it with
// new data, correct the offset so that this operation can occur again later.
int _flush_buff(FILE_J* fp) {
  // do nothing if the buffer isn't dirty;
  // this frees us from needing to check
  // if the write flag is set.
  if (!fp->dirty) {
    return 0;
  }

  // check error flags and quit if necessary.
  // if (fp->flags._EOF | fp->flags._ERR) {
  //  printf("_flush_buf() | cannot write to file.\n");
  //  return EOF;
  //}

  // write the data buffer to the file
  write(fp->fd, fp->buff, writesize);
  if (errno) {
    perror("_flush_buf(): Couldn't flush buffer - ");
    fp->flags._ERR = true;
    return -1;
  }

  // reset the file pointer, replenish the buffer
  fp->ptr = fp->buff;
  fp->dirty = 0;
  _fill_buff(fp);

  printf("_flush_buf() | buffer is flushed.\n");
  return 0;
}
