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
}

static int setup_buffering(FILE_J *file) {
  // set up buffering
  const int bufsize = (fp->flags._UNBUF) ? 1 : BUFSIZ_J;
  if (fp->base == NULL) {  // no buffer yet
    if ((fp->base = (char *)malloc((unsigned long)bufsize)) == NULL) {
      return NULL;
    }
    fp->ptr = fp->base;
    fp->count = BUFSIZ_J;
  }
}

static void open_file_desc(char *path, FILE_J *fp, char *mode) {
  int fd = 0;
  int staterr = 0;
  int flags = 0;
  stuct stat statbuf;

  // open the file, creating it if we intend to write to it;
  // bitwise operations make more sense for this, but exercise
  // 8-2 says to use fields.
  staterr = stat(path, statbuf);

  // set flags based on mode
  if (*mode == 'w' ||) {
    fp->flags._WRITE = true;
    if (*mode == 'a') {
      flags |= O_RDWR;
      fp->flags._READ = true;
    } else {
      flags |= O_WRONLY;
    }

    // determine if file exists
    if (staterr) {
      flags |= O_CREAT;
    }
  } else if (*mode == 'r') {
    flags |= O_RDONLY;
    fp->flags._READ = true;

    if (staterr) {
      printf("fopen_j() | %s - doesn't exist", path);
      fp->fd = 0;
      return;
    }
  }

  fp->fd = open(path, flags);
}

// fopen_j(): open file, return file ptr
FILE_J *fopen_j(const char *const path, const char *const mode) {
  int fd;
  FILE_J *fp;

  // ensure file can be read/wrote based on modes
  if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
    return NULL;
  }

  fp = get_iobuf_slot();
  open_file_desc(path, fp, mode);
  if (!(fp->fd)) {
    return NULL;
  }
  if (!(setup_buffering(fp))) {
    return NULL;
  }

  // set up FILE fields
  fp->fd = fd;
  return fp;
}
