#include <stddef.h>
#include <sys/types.h>

#define MAX_PATH 255

#ifndef NAME_MAX
#define NAME_MAX 16  // longest filename component, system dependent
#endif

#ifndef DIRSIZ
#define DIRSIZ 16
#endif

// portable directory entry
typedef struct Dirent {
  size_t inode;   // inode number
  char name[16];  // 15 char name + \0
} Dirent;

// defined in dirent.h, but cannot access __dirstream
typedef struct DIR {  // Minimal DIR, no buffering, etc.
  Dirent d;           // directory entry
  int fd;             // file descriptor for directory
  int align;          // not used; for alignment purposes
} DIR;

struct direct {
  ino_t d_ino;
  char d_name[DIRSIZ];
};  // directory entry

void fsize(char *);

void dirwalk(char *, void (*fcn)(char *));

// defined in dirent.h
DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);
