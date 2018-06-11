#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "8.5.h"

// main(): recurses through current directory tree calling fsize
int main(int argc, char **argv) {
  if (argc == 1) {
    fsize(".");
  } else {
    while (--argc > 0) {
      fsize(*(++argv));
    }
  }
  return 0;
}

// fsize(): print size and permission bits of all files in dir, recurse into
// subdirs
void fsize(const char *const name) {
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

// dirwalk: recursively apply fcn to all files in dir
void dirwalk(const char *const dir, void (*fcn)(const char *const)) {
  char name[MAX_PATH];
  struct dirent *dp;
  DIR *dfd;

  if ((dfd = opendir(dir)) == NULL) {
    fprintf(stderr, "dirwalk: can't open %s\n", dir);
    return;
  }

  while ((dp = readdir(dfd)) != NULL) {
    if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
      continue;  // skip self and parent
    }
    if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)) {
      fprintf(stderr, "dirwalk: name %s%s too long.\n", dir, dp->d_name);
    } else {
      sprintf(name, "%s/%s", dir, dp->d_name);
      (*fcn)(name);
    }
  }
  closedir(dfd);
}
