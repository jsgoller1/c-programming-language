#include <stdio.h>
#include <string.h>
//#include <sys/dir.h>
#include <unistd.h>

#include "fsize.h"

// readdir: read directory entries in sequence
Dirent *readdir(DIR *dp) {
  struct direct dirbuf;  // local directory structure
  static Dirent d;       // return: portable structure

  while (read(dp->fd, (char *)&dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
    if (dirbuf.d_ino == 0) {
      continue;  // slot not in use
    }
    d.inode = dirbuf.d_ino;
    strncpy(d.name, dirbuf.d_name, DIRSIZ);
    d.name[DIRSIZ - 1] = '\0';  // ensure termination
    return &d;
  }
  return NULL;
}
