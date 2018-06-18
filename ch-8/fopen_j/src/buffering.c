#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "fopen_j.h"

// print_buffer(): displays contents of buffer, useful for debugging.
void print_buffer(FILE_J* fp) {
  printf("print_buffer() | Buffer contents:\n");
  for (int i = 0; i < BUFF_SIZE; i++) {
    printf("%c", fp->buff[i]);
  }
  printf("\n----\n");
}

// fflush_j(): empty a FILE_J's buffer to its file descriptor, and correct
// the position. Can be called at will / arbitrarily many times.
int fflush_j(FILE_J* fp) {
  int flush, fill;
  flush = _flushbuff(fp);
  fill = _fillbuff(fp);
  return flush && fill;
}

//_fillbuff(): refill the I/O buffer with characters from the file
int _fillbuff(FILE_J* fp) {
  int count;
  count = (int)read(fp->fd, fp->buff, BUFF_SIZE);
  if (count == -1) {
    perror("_fillbuff: ");
    fp->flags._ERR = true;
    return -1;
  }

  // Seek the fd back to original place; writes to buff
  // need to be written back to the file in the correct
  // place.
  off_t status;
  status = lseek(fp->fd, -count, SEEK_CUR);
  if (status == -1) {
    perror("_fillbuff: ");
    fp->flags._ERR = true;
    return -1;
  }

  return 0;
}

// _flush_buff(): write fp's buffer to the file descriptor.
int _flushbuff(FILE_J* fp) {
  if (fp->flags._ERR) {
    printf("_flushbuff() | cannot write to file.\n");
    return -1;
  }

  long written;
  written = write(fp->fd, fp->buff, (size_t)(fp->ptr - fp->buff));
  if (written == -1) {
    perror("_flushbuff(): Couldn't flush buffer to file. ");
    fp->flags._ERR = true;
    return -1;
  }

  return 0;
}
