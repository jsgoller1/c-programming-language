#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>

#include "fopen_j.h"

#define PERMS 0666  // rw for owner, group, others

// fopen_j(): open file, return file ptr
FILE_J *fopen_j(char *name, char *mode) {
  int fd;
  FILE_J *fp;

  // ensure file can be read/wrote based on modes
  if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
    return NULL_J;
  }

  // find available slot for an _iobuf, or quit if we can't
  for (fp = _iobufs; fp < _iobufs + OPEN_MAX; fp++) {
    if ((fp->flags._READ | fp->flags._WRITE) == 0) {
      break;
    }
  }
  if (fp >= _iobufs + OPEN_MAX) {
    return NULL_J;
  }

  // open the file, creating it if we intend to write to it.
  if (*mode == 'w') {
    fd = creat(name, PERMS);
  } else if (*mode == 'a') {
    if ((fd = open(name, O_WRONLY, 0)) == -1) {
      fd = creat(name, PERMS);
    }
    lseek(fd, 0L, 2);
  } else {
    fd = open(name, O_RDONLY, 0);
  }
  if (fd == -1) {
    return NULL_J;
  }

  // set up FILE fields
  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL_J;
  fp->flags._READ = true;
  fp->flags._WRITE = (*mode == 'r') ? false : true;
  return fp;
}
