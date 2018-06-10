#include "fsize.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// fsize(): print size of file "name"
void fsize(char *name) {
  struct stat stbuf;

  if (stat(name, &stbuf) == -1) {
    fprintf(stderr, "fsize: can't access %s\n", name);
    return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
    dirwalk(name, fsize);
  }
  printf("%81d %s \n", stbuf.st_size, name);
}
