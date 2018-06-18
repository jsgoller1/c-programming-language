#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "fopen_j.h"

#define PERMS 0666  // rw for owner, group, others

// open_file_desc(): private function for handling flags
// and opening the file descriptor
static void open_file_desc(const char *const path, FILE_J *fp,
                           const char *const mode) {
  int flags = 0;
  struct stat statbuf;

  // set flags for writing
  if (*mode == 'w') {
    if (stat(path, &statbuf)) {
      flags |= (O_CREAT | O_TRUNC);
    }
    fp->flags._WRITE = true;
    flags |= O_WRONLY;
  }  // set flags for reading
  else if (*mode == 'r') {
    if (stat(path, &statbuf)) {
      fp->fd = -1;
      return;
    }
    fp->flags._READ = true;
    flags |= O_RDONLY;
  }  // set flags for both
  else if (*mode == 'a') {
    if (stat(path, &statbuf)) {
      flags |= (O_CREAT | O_TRUNC);
    }
    fp->flags._WRITE = true;
    fp->flags._READ = true;
    flags |= O_RDWR;
  }  // handle invalid flags
  else {
    fp->fd = -1;
    return;
  }

  fp->fd = open(path, flags, PERMS);
  if (fp->fd == -1) {
    perror("fopen_j() | file failed to open: ");
  }
}

// setup_buffering(): private function for intializing the I/O buffer.
static int setup_buffering(FILE_J *fp) {
  // set up buffering
  if ((fp->buff = (char *)malloc((unsigned long)BUFF_SIZE)) == NULL) {
    return -1;
  }
  fp->ptr = fp->buff;

  return 0;
}

// fopen_j(): open file, return file ptr
FILE_J *fopen_j(const char *const path, const char *const mode) {
  FILE_J *fp;

  // ensure file can be read/written based on modes
  if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
    return NULL;
  }

  // space for file
  fp = malloc(sizeof(FILE_J));
  if (fp == NULL) {
    printf("fopen_j() | couldn't create file.\n");
    return NULL;
  }

  open_file_desc(path, fp, mode);
  if (!(fp->fd)) {
    printf("fopen_j() | couldn't open fd.\n");
    free(fp);
    return NULL;
  }

  if (setup_buffering(fp)) {
    printf("fopen_j() | couldn't set up buffering.\n");
    free(fp);
    return NULL;
  }

  fp->flags._ERR = 0;
  fp->flags._EOF = 0;
  return fp;
}
