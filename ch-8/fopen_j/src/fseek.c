#include <stdio.h>
#include <unistd.h>

#include "fopen_j.h"

// fseek(): on a seekable file, change the file offset.
int fseek_j(FILE_J* const fp, const long offset, const int whence) {
  char* position;

  // validate whence, set up position
  if (whence == SEEK_SET) {
    position = fp->buff + offset;
  } else if (whence == SEEK_CUR) {
    position = fp->ptr + offset;
  } else {
    printf(
        "fseek() | invalid whence (only SEEK_SET and SEEK_CUR currently "
        "implemented).\n");
    return -1;
  }

  // if the seek occurs within the buffer, just change the pointer and return.
  if ((fp->buff <= position) && (position < fp->buff + BUFF_SIZE)) {
    fp->ptr = position;
    return 0;
  }

  // if the seek goes outside the buffer, first flush, then seek the
  // fd to the correct location, fill the buffer, and seek back for
  // shadowing.
  _flush_buff(fp);
  lseek(fp->fd, position, SEEK_SET);
  _fill_buff(fp);
  lseek(fp->fd, position, SEEK_SET);

  return 0;
}
