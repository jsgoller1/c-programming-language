#define NAME_MAX 14  // longest filename component, system dependent

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

// portable directory entry
typedef struct {
  size_t inode;             // inode number
  char name[NAME_MAX + 1];  // name + \0
} Dirent;

typedef struct {  // Minimal DIR, no buffering, etc.
  int fd;         // file descriptor for directory
  Dirent d;       // directory entry
} DIR;

struct direct {
  ino_t d_ino;
  char d_name[DIRSIZ];
} // directory entry

void fsize(char *);

void dirwalk(char *, void (*fcn)(char *));
DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);
