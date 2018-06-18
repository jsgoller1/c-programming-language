#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "fopen_j.h"

// print_buffer(): displays contents of buffer, useful for debugging.
void print_buffer(FILE_J* fp) {
  printf("Buffer contents:\n");
  for (int i = 0; i < BUFF_SIZE; i++) {
    printf("%c", fp->buff[i]);
  }
  printf("\n----\n");
}

// fflush_j(): empty a FILE_J's buffer to its file descriptor, and correct
// the position. Can be called at will / arbitrarily many times.
int fflush_j(FILE_J* fp) { return _flushbuff(fp) && _fillbuff(fp); }

//_fill_buff(): refill the I/O buffer with characters from the file,
// and seek back to the original offset in the file.
int _fillbuff(FILE_J* fp) {
  int count;
  off_t status;

  count = (int)read(fp->fd, fp->buff, BUFF_SIZE);
  if (count == -1) {
    perror("_fillbuff: ");
    fp->flags._ERR = true;
    return -1;
  } else {
    printf("_fillbuff() | count: %d.\n", count);
  }

  status = lseek(fp->fd, count, SEEK_CUR);
  if (status == -1) {
    perror("_fillbuff: ");
    fp->flags._ERR = true;
    return -1;
  }

  /*
    if (count <= 0) {
      if (count == 0) {
        fp->flags._EOF = true;
      } else {
        fp->flags._ERR = true;
        return -1;
      }
    }
  */

  printf("_flushbuff() | buffer is filled and fd is corrected.\n");
  return 0;
}

// _flush_buff: Dump fp's buffer to the file descriptor.
int _flushbuff(FILE_J* fp) {
  // check error flags and quit if necessary.
  if (fp->flags._ERR) {
    printf("_flushbuff() | cannot write to file.\n");
    return -1;
  }

  // write the data buffer to the file
  long written;
  written = write(fp->fd, fp->buff, BUFF_SIZE);
  if (written == -1) {
    perror("_flushbuff(): Couldn't flush buffer. ");
    fp->flags._ERR = true;
    return -1;
  }

  printf("_flushbuff() | buffer is flushed.\n");
  return 0;
}
