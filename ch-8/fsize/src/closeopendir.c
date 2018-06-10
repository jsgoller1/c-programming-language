#include "fsize.h"

// opendir(): open a directory for readdir calls
DIR *opendir(char *dirname) {
  int fd;
  struct stat stbuf;
  DIR *dp;

  if ((fd = open(dirname, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 ||
      (stbuf.st_mode & S_IFMT) != S_IFDIR ||
      (dp = (DIR *)malloc(sizeof(DIR))) == NULL) {
    return NULL;
  }
  dp->fd = fd;
  return dp;
}

// closedir(): close directory opened by opendir
void closedir(DIR *dp) {
  if (dp) {
    close(dp->fd);
    free(dp);
  }
}
