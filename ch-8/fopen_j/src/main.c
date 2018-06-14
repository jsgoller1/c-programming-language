#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "fopen_j.h"

FILE_J _iobufs[OPEN_MAX];
/*
  // initialize with stdin/out/err
  {0, NULL_J, NULL_J, 0},
  {0, NULL_J, NULL_J, 1},
  {0, NULL_J, NULL_J, 2},
*/

int main() {
  char string1[] = "abcdefghijklmnopqrstuvwxyz";
  char string2[] = "124567890";
  char result[100];

  char filename[] = "test.txt";
  char mode = 'a';
  FILE_J* file = fopen_j(filename, &mode);

  for (int i = 0; i < (int)strlen(string1); i++) {
    putc_j(string1[i], file);
  }
  fclose_j(file);

  /*
  file = fopen_j(filename, &mode);

  for (int i = 0; i < (int)strlen(string1); i++) {
    result[i] = getc_j(string1[i], file);
  }

  getc_j(contents1, 1, 10, file);
  fclose_j(file);
*/
}
