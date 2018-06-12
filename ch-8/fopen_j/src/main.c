#include <stdbool.h>
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
  char filename[] = "test.txt";
  char contents[] = "boop doop floop\n";
  char mode = 'a';
  FILE_J* file = fopen_j(filename, &mode);
  for (int i = 0; i < (int)strlen(contents); i++) {
    putc(contents[i], file);
  }
}
