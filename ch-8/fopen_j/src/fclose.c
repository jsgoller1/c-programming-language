#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fopen_j.h"

// fclose_j(): close fd, and clean up associated memory for FILE_J
int fclose_j(FILE_J* file) {
  if (_flushbuff(file) == -1) {
    printf("fclose_j() | couldn't flush buffer.\n");
    return -1;
  }

  if (close(file->fd) == -1) {
    perror("fclose_j() | Couldn't close file: ");
    return -1;
  }

  free(file->buff);
  free(file);
  return 0;
}
