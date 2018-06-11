#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "fsize.h"

// print file sizes
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
