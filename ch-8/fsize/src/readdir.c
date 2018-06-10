#include <sys/dir.h>

// readdir: read directory entries in sequence
Dirent *readdir(DIR *dp) {
  stuct dirent dirbuf;  // local directory structure
  static Dirent d;      // return: portable structure

  while (read(dp->fd, (char *)&dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
    if (dirbuf.d_ino == 0) {
      continue  // slot not in use
    }
    d.ino = dirbuf.d_ino;
    strncpy(d.name, dirbuf.d_name, DIRSIZ);
    d.name[DIRSIZ] = '\0';  // ensure termination
    return &d;
  }
  return NULL;
}
