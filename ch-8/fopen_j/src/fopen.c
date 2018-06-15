#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "fopen_j.h"

#define PERMS 0666  // rw for owner, group, others

static FILE_J *get_iobuf_slot(void) {
  FILE_J *fp;

  // find available slot for an _iobuf, or quit if we can't;
  // since no file is ever open for "neither reading or writing",
  // check flags to see if the bits are set.
  for (fp = _iobufs; fp < _iobufs + OPEN_MAX; fp++) {
    if ((fp->flags._READ | fp->flags._WRITE) == 0) {
      break;
    }
  }
  if (fp >= _iobufs + OPEN_MAX) {
    return NULL;
  }

  return fp;
}

static int setup_buffering(FILE_J *fp) {
  // set up buffering
  const int bufsize = (fp->flags._UNBUF) ? 1 : BUFSIZ_J;
  if (fp->base == NULL) {  // no buffer yet
    if ((fp->base = (char *)malloc((unsigned long)bufsize)) == NULL) {
      return -1;
    }
    fp->ptr = fp->base;
    fp->count = BUFSIZ_J;
  }
  return 0;
}

static void open_file_desc(const char *const path, FILE_J *fp,
                           const char *const mode) {
  int flags = 0;
  struct stat statbuf;

  // set flags for writing
  if (*mode == 'w') {
    if (stat(path, &statbuf)) {
      flags |= O_CREAT;
    }
    fp->flags._WRITE = true;
    flags |= O_WRONLY;
  }  // set flags for reading
  else if (*mode == 'r') {
    if (stat(path, &statbuf)) {
      printf("fopen_j() | %s - doesn't exist.\n", path);
      fp->fd = -1;
      return;
    }
    fp->flags._READ = true;
    flags |= O_RDONLY;
  }  // set flags for both
  else if (*mode == 'a') {
    if (stat(path, &statbuf)) {
      flags |= O_CREAT;
    }
    fp->flags._WRITE = true;
    fp->flags._READ = true;
    flags |= O_RDWR;
  }  // handle invalid flags
  else {
    printf("fopen_j() | %s - illegal mode.\n", mode);
    fp->fd = -1;
    return;
  }

  fp->fd = open(path, flags, PERMS);
}

// fopen_j(): open file, return file ptr
FILE_J *fopen_j(const char *const path, const char *const mode) {
  FILE_J *fp;

  // ensure file can be read/wrote based on modes
  if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
    return NULL;
  }

  fp = get_iobuf_slot();
  open_file_desc(path, fp, mode);
  if (!(fp->fd)) {
    printf("fopen_j() | couldn't open fd.\n");
    return NULL;
  }

  if (setup_buffering(fp)) {
    printf("fopen_j() | couldn't set up buffering.\n");
    return NULL;
  }

  return fp;
}
