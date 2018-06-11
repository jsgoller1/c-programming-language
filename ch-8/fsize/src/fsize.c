#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "fsize.h"

// fsize(): print size of file "name"
void fsize(const char* const name) {
  struct stat stbuf;

  if (stat(name, &stbuf) == -1) {
    fprintf(stderr, "fsize: can't access %s\n", name);
    return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
    dirwalk(name, fsize);
  }
  printf("%8ld %4o %s\n", stbuf.st_size, stbuf.st_mode & 0x0fff, name);
}
