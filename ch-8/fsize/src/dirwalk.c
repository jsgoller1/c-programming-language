#include <dirent.h>
#include <stdio.h>
#include <string.h>

#include "fsize.h"

// dirwalk: apply fcn to all files in dir
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
