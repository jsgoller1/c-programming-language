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
// the position.
int fflush_j(FILE_J* fp) {
  _flush_buff(fp);
  lseek(fp->fd, -BUFF_SIZE, SEEK_CUR);
  return 0;
}

//_fill_buff(): refill the I/O buffer with characters from the file,
// and seek back to the original offset in the file.
int _fill_buff(FILE_J* fp) {
  int count;

  // quit if flags indicate reading isn't possible.
  // if (fp->flags._READ & !(fp->flags._EOF | fp->flags._ERR)) {
  //  return EOF;
  //}

  count = (int)read(fp->fd, fp->buff, BUFF_SIZE);
  printf("_fill_buff() | count: %d.\n", count);

  if (count <= 0) {
    if (count == 0) {
      fp->flags._EOF = true;
    } else {
      fp->flags._ERR = true;
    }
    return EOF;
  }

  fp->dirty = 0;
  return 0;
}

// _flush_buff: Dump fp's buffer to the file descriptor, fill it with
// new data, correct the offset so that this operation can occur again later.
int _flush_buff(FILE_J* fp) {
  // check error flags and quit if necessary.
  if (fp->flags._ERR) {
    printf("_flush_buf() | cannot write to file.\n");
    return EOF;
  }

  // if the buffer doesn't need writing,
  // advance it as though it had been written
  // and return.
  if (!fp->dirty) {
    lseek(fp->fd, BUFF_SIZE, SEEK_CUR);
    return 0;
  }

  // write the data buffer to the file
  long written;
  written = write(fp->fd, fp->buff, BUFF_SIZE);
  if (written == -1) {
    perror("_flush_buf(): Couldn't flush buffer - ");
    fp->flags._ERR = true;
    return -1;
  }

  // Clear all data in the buffer; we might not actually want to do this.
  // memset(fp->buff, '\0', BUFF_SIZE);
  fp->dirty = 0;

  printf("_flush_buf() | buffer is flushed.\n");
  return 0;
}
