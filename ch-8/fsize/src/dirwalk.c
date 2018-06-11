#include <stdio.h>
#include <string.h>

#include "fsize.h"

// dirwalk: apply fcn to all files in dir
void dirwalk(char *dir, void (*fcn)(char *)) {
  char name[MAX_PATH];
  Dirent *dp;
  DIR *dfd;

  if ((dfd = opendir(dir)) == NULL) {
    fprintf(stderr, "dirwalk: can't open %s\n", dir);
    return;
  }
  while ((dp = readdir(dfd)) != NULL) {
    if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0) {
      continue;  // skip self and parent
    }
    if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name)) {
      fprintf(stderr, "dirwalk: name %s%s too long.\n", dir, dp->name);
    } else {
      sprintf(name, "%s%s", dir, dp->name);
      (*fcn)(name);
    }
  }
  closedir(dfd);
}
