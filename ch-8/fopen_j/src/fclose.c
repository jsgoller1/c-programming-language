#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fopen_j.h"

// fclose_j(): close fd, and clean up associated memory for FILE_J
int fclose_j(FILE_J* file) {
  _flushbuff(file);

  if (close(file->fd) == -1) {
    perror("Couldn't close file: ");
    return -1;
  }

  free(file->buff);
  free(file);
  return 0;
}
