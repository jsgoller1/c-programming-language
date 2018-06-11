#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "common.h"

/*
 * 8.1: Rewrite the program cat from Chapter 7 using read, write,
 * open and close instead of their standard library equivalents.
 * Perform experiments to determine the relative speeds of the
 * two versions.
 */

int main(int argc, char** argv) {
  if (argc < 1) {
    printf("usage: cat <filename> ...");
  }

  int fd = 0;
  char temp[MAXLEN];
  for (int i = 0; i < argc; i++) {
    char* filename = argv[i];

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
      perror("cat");
      return -1;
    }

    while (read(fd, temp, MAXLEN) > 0) {
      printf("%s", temp);
    }
    printf("\n");
    close(fd);
  }
  return 0;
}
