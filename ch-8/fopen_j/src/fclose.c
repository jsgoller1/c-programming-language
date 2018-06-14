#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fopen_j.h"

// fclose_j(): clean up and close a FILE_J
int fclose_j(FILE_J* file) {
  fflush_j(file);
  free(file->base);
  close(file->fd);
  if (errno) {
    perror("Couldn't close file: ");
    return -1;
  }
  return 0;
}
