#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
// #include "dirent.h"
// #include "syscalls.h"

// print file sizes
main(int argc, char **argv) {
  if (argc == 1) {
    fsize(".");
  } else {
    while (--argc > 0) {
      fsize(*(++argv));
    }
  }
  return 0;
}
