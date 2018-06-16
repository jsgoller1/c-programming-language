#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fopen_j.h"

// fclose_j(): clean up and close a FILE_J
int fclose_j(FILE_J* file) {
  printf("fclose_j() | closing the file...\n");
  _flush_buff(file);

  int closed;
  closed = close(file->fd);
  if (closed == -1) {
    perror("Couldn't close file: ");
    return -1;
  }

  free(file->buff);
  free(file);
  return 0;
}
